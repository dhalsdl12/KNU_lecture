import numpy as np
import torch
import torchvision.datasets as datasets
import torchvision.transforms as transforms

from torch.utils.data import DataLoader, Dataset
from torch import nn
import torch.optim as optim
from sklearn.model_selection import KFold


# 하이퍼 매개변수 설정
batch_size=256
n_epoch=2
k=2 # 5-겹

# Fashion MNIST 읽어 와서 신경망에 입력할 형태로 변환
train_dataset = datasets.FashionMNIST(root='./data', train=True, transform=transforms.ToTensor(), download=True)
test_dataset = datasets.FashionMNIST(root='./data', train=False, transform=transforms.ToTensor())

train_loader = DataLoader(dataset=train_dataset, batch_size=batch_size, shuffle=True)
test_loader = DataLoader(dataset=test_dataset, batch_size=batch_size, shuffle=False)

# 신경망 구조 설정
n_input=784
n_hidden1=1024
n_hidden2=512
n_hidden3=512
n_hidden4=512
n_output=10

# 모델을 설계해주는 함수(모델을 나타내는 객체 model을 반환)
class DMLP(nn.Module):
    def __init__(self):
        super(DMLP, self).__init__()
        self.fc1 = nn.Linear(n_input, n_hidden1)
        self.fc2 = nn.Linear(n_hidden1, n_hidden2)
        self.fc3 = nn.Linear(n_hidden2, n_hidden3)
        self.fc4 = nn.Linear(n_hidden3, n_hidden4)
        self.fc5 = nn.Linear(n_hidden4, n_output)

    def forward(self, x):
        x = nn.functional.relu(self.fc1(x))
        x = nn.functional.relu(self.fc2(x))
        x = nn.functional.relu(self.fc3(x))
        x = nn.functional.relu(self.fc4(x))
        x = nn.Softmax(dim=1)(self.fc5(x))
        return x

def train(model, optimizer, criterion, epochs):
    train_accuracies, test_accuracies = [], []
    for epoch in range(epochs):
        train_loss = 0.0
        train_correct = 0.0
        for batch_idx, (data, target) in enumerate(train_loader):
            optimizer.zero_grad()
            data = data.view(-1, n_input)
            outputs = model(data)
            _, preds = torch.max(outputs.data, 1)
            target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
            loss = criterion(outputs,  target_one_hot.float())
            train_correct += torch.sum(preds == target)
            train_loss += loss.item() * data.size(0)
            loss.backward()
            optimizer.step()

        train_loss /= len(train_loader.dataset)
        # train_losses.append(train_loss)
        train_accuracy = 100. * train_correct / len(train_loader.dataset)
        train_accuracies.append(train_accuracy)

        
        test_loss = 0.0
        test_correct = 0.0
        with torch.no_grad():
            for data, target in test_loader:
                data = data.view(-1, n_input)
                outputs = model(data)
                _, preds = torch.max(outputs.data, 1)
                target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
                loss = criterion(outputs, target_one_hot.float())
                test_correct += torch.sum(preds == target)
                test_loss += loss.item() * data.size(0)
            test_loss /= len(test_loader.dataset)
            # test_losses.append(test_loss)
            test_accuracy = 100. * test_correct / len(test_loader.dataset)
            test_accuracies.append(test_accuracy)

        print(f'Epoch {epoch+1}/{epochs}: Train Loss: {train_loss:.4f}, Train Acc: {train_accuracy:.2f}%, Val Loss: {test_loss:.4f}, Val Acc: {test_accuracy:.2f}%')
    return train_accuracies, test_accuracies

def cross_validation(opt):
    accuracy=[]
    for train_index,val_index in KFold(k).split(x_train):
        xtrain,xval=torch.tensor(x_train[train_index]),torch.tensor(x_train[val_index])
        ytrain,yval=torch.tensor(y_train[train_index]),torch.tensor(y_train[val_index])
        dmlp=DMLP()
        criterion = nn.CrossEntropyLoss()
        if opt == 'sgd':
            optimizer = optim.SGD(dmlp.parameters(), lr=0.01)
        elif opt == 'adam':
            optimizer = optim.Adam(dmlp.parameters(), lr=0.01)
        elif opt == 'adagrad':
            optimizer = optim.Adagrad(dmlp.parameters(), lr=0.01)
        elif opt == 'rmsprop':
            optimizer = optim.RMSprop(dmlp.parameters(), lr=0.01)
        _, accuracy_k = train(dmlp, optimizer, criterion, n_epoch)
        accuracy_k = np.mean(accuracy_k)
    
        accuracy.append(accuracy_k)
    return accuracy

# 옵티마이저 4개에 대해 교차 검증을 실행
acc_sgd=cross_validation('sgd')
acc_adam=cross_validation('adam')
acc_adagrad=cross_validation('adagrad')
acc_rmsprop=cross_validation('rmsprop')

# 옵티마이저 4개의 정확률을 비교
print("SGD:",np.array(acc_sgd).mean())
print("Adam:",np.array(acc_adam).mean())
print("Adagrad:",np.array(acc_adagrad).mean())
print("RMSprop:",np.array(acc_rmsprop).mean())

import matplotlib.pyplot as plt

# 네 옵티마이저의 정확률을 박스플롯으로 비교
plt.boxplot([acc_sgd,acc_adam,acc_adagrad,acc_rmsprop],labels=["SGD","Adam","Adagrad","RMSprop"])
plt.grid()