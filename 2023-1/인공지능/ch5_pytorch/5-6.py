import torch
import torch.nn as nn
import torch.optim as optim

# OR 데이터 구축
x = torch.tensor([[0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0]])
y = torch.tensor([[-1], [1], [1], [1]])

n_input = 2
n_output = 1

class Perceptron(nn.Module):
    def __init__(self):
        super(Perceptron, self).__init__()
        self.layer = nn.Linear(n_input, n_output, bias=True)
        nn.init.uniform_(self.layer.weight, -1, 1)
        nn.init.zeros_(self.layer.bias)

    def forward(self, x):
        out = torch.tanh(self.layer(x))
        return out

perceptron = Perceptron()

criterion = nn.MSELoss()
optimizer = optim.SGD(params=perceptron.parameters(), lr=0.1)

# 500세대까지 학습(100세대마다 학습 정보 출력)
epochs = 500
for i in range(epochs):
    optimizer.zero_grad()
    outputs = perceptron(x)
    loss = criterion(outputs, y.float())
    loss.backward()
    optimizer.step()
    # if(i%100==0):
    print('loss at epoch',i,'=',loss.detach().numpy())
    
res = perceptron(x)
print(res.detach().numpy())