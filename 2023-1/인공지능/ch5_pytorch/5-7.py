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

n_input = 784
n_hidden = 1024
n_output = 10

class MLP(nn.Module):
    def __init__(self):
        super(MLP, self).__init__()
        self.fc1 = nn.Linear(n_input, n_hidden)
        self.fc2 = nn.Linear(n_hidden, n_output)

    def forward(self, x):
        x = torch.tanh(self.fc1(x))
        x = torch.tanh(self.fc2(x))
        return x

mlp = MLP()

criterion = nn.MSELoss()
optimizer = Adam(mlp.parameters(), lr=0.001)

epochs = 30
train_losses = []
train_accuracies = []
test_losses = []
test_accuracies = []

for epoch in range(epochs):
    train_loss = 0.0
    train_correct = 0.0
    for batch_idx, (data, target) in enumerate(train_loader):
        optimizer.zero_grad()
        data = data.view(-1, n_input)
        outputs = mlp(data)
        _, preds = torch.max(outputs.data, 1)
        target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
        loss = criterion(outputs,  target_one_hot.float())
        train_correct += torch.sum(preds == target)
        train_loss += loss.item() * data.size(0)
        loss.backward()
        optimizer.step()

    train_loss /= len(train_loader.dataset)
    train_losses.append(train_loss)
    train_accuracy = 100. * train_correct / len(train_loader.dataset)
    train_accuracies.append(train_accuracy)

    
    test_loss = 0.0
    test_correct = 0.0
    with torch.no_grad():
        for data, target in test_loader:
            data = data.view(-1, n_input)
            outputs = mlp(data)
            _, preds = torch.max(outputs.data, 1)
            target_one_hot = torch.nn.functional.one_hot(target, num_classes=10) # 원핫 코드로 변환
            loss = criterion(outputs, target_one_hot.float())
            test_correct += torch.sum(preds == target)
            test_loss += loss.item() * data.size(0)
        test_loss /= len(test_loader.dataset)
        test_losses.append(test_loss)
        test_accuracy = 100. * test_correct / len(test_loader.dataset)
        test_accuracies.append(test_accuracy)

    print(f'Epoch {epoch+1}/{epochs}: Train Loss: {train_loss:.4f}, Train Acc: {train_accuracy:.2f}%, Val Loss: {test_loss:.4f}, Val Acc: {test_accuracy:.2f}%')

print(f'정확률은 {test_accuracy:.2f}%')
import matplotlib.pyplot as plt

# 정확률 곡선
plt.plot(train_accuracies)
plt.plot(test_accuracies)
plt.title('Model accuracy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend(['Train','Validation'], loc='upper left')
plt.grid()
plt.show()

# 손실 함수 곡선
plt.plot(train_losses)
plt.plot(test_losses)
plt.title('Model loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend(['Train','Validation'], loc='upper right')
plt.grid()
plt.show()