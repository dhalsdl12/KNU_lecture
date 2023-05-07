import torch

# OR 데이터 구축
x = torch.tensor([[0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0]])
y = torch.tensor([[-1], [1], [1], [1]])

# 가중치 초기화
w = (torch.rand(2, 1) - 0.5).requires_grad_(True)
b = torch.zeros(1)

# 옵티마이저
opt = torch.optim.SGD(params=[w, b], lr=0.1)

# 전방 계산(식 (4.3))
def forward():
    s = torch.add(torch.matmul(x, w), b)
    o = torch.tanh(s)
    return o

# 손실 함수 정의
def loss():
    o = forward()
    return torch.mean((y-o)**2)

# 500세대까지 학습(100세대마다 학습 정보 출력)
for i in range(500):
    opt.zero_grad()
    loss().backward()
    opt.step()
    if(i%100==0): print('loss at epoch',i,'=',loss().detach().numpy())

# 학습된 퍼셉트론으로 OR 데이터를 예측
o = forward()
print(o)
