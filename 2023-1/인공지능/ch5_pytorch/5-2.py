import torch
import numpy as np

t = torch.rand(2, 3)
n = np.random.uniform(0, 1, [2, 3])
print("pytorch로 생성한 텐서:\n",t,"\n")
print("numpy로 생성한 ndarray:\n",n,"\n")

res=t+n # 텐서 t와 ndarray n의 덧셈
print("덧셈 결과:\n",res)