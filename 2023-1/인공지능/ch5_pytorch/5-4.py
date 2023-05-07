import torch

# OR 데이터 구축
x = torch.tensor([[0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0]])
y = torch.tensor([[-1], [1], [1], [1]])

# [그림 4-3(b)]의 퍼셉트론
w = torch.tensor([[1.0], [1.0]])
b = torch.tensor(-0.5)

# 식 4.3의 퍼셉트론 동작
s = torch.add(torch.matmul(x, w), b)
o = torch.sign(s)

print(o)