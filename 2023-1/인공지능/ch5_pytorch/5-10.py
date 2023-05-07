import numpy as np
import torch
import torchvision.datasets as datasets
import torchvision.transforms as transforms

from torch.utils.data import DataLoader, Dataset
from torch import nn
from torch.optim import Adam

# MNIST 읽어 와서 신경망에 입력할 형태로 변환
train_dataset = datasets.MNIST(root='./data', train=True, transform=transforms.ToTensor(), download=True)
test_dataset = datasets.MNIST(root='./data', train=False, transform=transforms.ToTensor())

train_loader = DataLoader(dataset=train_dataset, batch_size=128, shuffle=True)
test_loader = DataLoader(dataset=test_dataset, batch_size=128, shuffle=False)

n_input=784
n_hidden1=1024
n_hidden2=512
n_hidden3=512
n_hidden4=512
n_output=10

class DMLP(nn.Module):
    def __init__(self):
        super(DMLP, self).__init__()
        self.fc1 = nn.Linear(n_input, n_hidden1)
        self.fc2 = nn.Linear(n_hidden1, n_hidden2)
        self.fc3 = nn.Linear(n_hidden2, n_hidden3)
        self.fc4 = nn.Linear(n_hidden3, n_hidden4)
        self.fc5 = nn.Linear(n_hidden4, n_output)

    def forward(self, x):
        x = torch.tanh(self.fc1(x))
        x = torch.tanh(self.fc2(x))
        x = torch.tanh(self.fc3(x))
        x = torch.tanh(self.fc4(x))
        x = nn.Softmax(dim=1)(self.fc5(x))
        return x
    
epochs = 30
# DMLP_MSE
mlp_mse = DMLP()
criterion_mse = nn.MSELoss()
optimizer_mse = Adam(mlp_mse.parameters(), lr=0.0001)

train_losses_mse = []
train_accuracies_mse = []
test_losses_mse = []
test_accuracies_mse = []

for epoch in range(epochs):
    train_loss = 0.0
    train_correct = 0.0
    for batch_idx, (data, target) in enumerate(train_loader):
        optimizer_mse.zero_grad()
        data = data.view(-1, n_input)
        outputs = mlp_mse(data) 
        _, preds = torch.max(outputs.data, 1)
        target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
        loss = criterion_mse(outputs,  target_one_hot.float())
        train_correct += torch.sum(preds == target)
        train_loss += loss.item() * data.size(0)
        loss.backward()
        optimizer_mse.step()

    train_loss /= len(train_loader.dataset)
    train_losses_mse.append(train_loss)
    train_accuracy = 100. * train_correct / len(train_loader.dataset)
    train_accuracies_mse.append(train_accuracy)

    
    test_loss = 0.0
    test_correct = 0.0
    with torch.no_grad():
        for data, target in test_loader:
            data = data.view(-1, n_input)
            outputs = mlp_mse(data)
            _, preds = torch.max(outputs.data, 1)
            target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
            loss = criterion_mse(outputs, target_one_hot.float())
            test_correct += torch.sum(preds == target)
            test_loss += loss.item() * data.size(0)
        test_loss /= len(test_loader.dataset)
        test_losses_mse.append(test_loss)
        test_accuracy_mse = 100. * test_correct / len(test_loader.dataset)
        test_accuracies_mse.append(test_accuracy_mse)

    print(f'Epoch {epoch+1}/{epochs}: Train Loss: {train_loss:.4f}, Train Acc: {train_accuracy:.2f}%, Val Loss: {test_loss:.4f}, Val Acc: {test_accuracy_mse:.2f}%')


# DMLP_CE
mlp_ce = DMLP()
criterion_ce = nn.CrossEntropyLoss()
optimizer_ce = Adam(mlp_ce.parameters(), lr=0.0001)

train_losses_ce = []
train_accuracies_ce = []
test_losses_ce = []
test_accuracies_ce = []

for epoch in range(epochs):
    train_loss = 0.0
    train_correct = 0.0
    for batch_idx, (data, target) in enumerate(train_loader):
        optimizer_ce.zero_grad()
        data = data.view(-1, n_input)
        outputs = mlp_ce(data)
        _, preds = torch.max(outputs.data, 1)
        target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
        loss = criterion_ce(outputs,  target_one_hot.float())
        train_correct += torch.sum(preds == target)
        train_loss += loss.item() * data.size(0)
        loss.backward()
        optimizer_ce.step()

    train_loss /= len(train_loader.dataset)
    train_losses_ce.append(train_loss)
    train_accuracy = 100. * train_correct / len(train_loader.dataset)
    train_accuracies_ce.append(train_accuracy)

    
    test_loss = 0.0
    test_correct = 0.0
    with torch.no_grad():
        for data, target in test_loader:
            data = data.view(-1, n_input)
            outputs = mlp_ce(data)
            _, preds = torch.max(outputs.data, 1)
            target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
            loss = criterion_ce(outputs, target_one_hot.float())
            test_correct += torch.sum(preds == target)
            test_loss += loss.item() * data.size(0)
        test_loss /= len(test_loader.dataset)
        test_losses_ce.append(test_loss)
        test_accuracy_ce = 100. * test_correct / len(test_loader.dataset)
        test_accuracies_ce.append(test_accuracy_ce)

    print(f'Epoch {epoch+1}/{epochs}: Train Loss: {train_loss:.4f}, Train Acc: {train_accuracy:.2f}%, Val Loss: {test_loss:.4f}, Val Acc: {test_accuracy_ce:.2f}%')

print(f'평균제곱오차의 정확률은 {test_accuracy_mse:.2f}%')
print(f'교차 엔트로피의 정확률은 {test_accuracy_ce:.2f}%')

# 하나의 그래프에서 두 모델을 비교
import matplotlib.pyplot as plt
plt.plot(train_accuracies_mse)
plt.plot(test_accuracies_mse)
plt.plot(train_accuracies_ce)
plt.plot(test_accuracies_ce)
plt.title('Model accuracy comparison between MSE and cross entropy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend(['Train_mse','Validation_mse','Train_ce','Validation_ce'], loc='best')
plt.grid()
plt.show()