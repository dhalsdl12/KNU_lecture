import torch
import torchvision.datasets as datasets

# MNIST 읽고 텐서 모양 출력
mnist_trainset = datasets.MNIST(root='./data', train=True, download=True)
x_train, y_train = mnist_trainset.data, mnist_trainset.targets
yy_train = torch.nn.functional.one_hot(y_train, num_classes=10) # 원핫 코드로 변환
print("MNIST: ", x_train.shape, y_train.shape, yy_train.shape)

# CIFAR-10 읽고 텐서 모양 출력
cifar_trainset = datasets.CIFAR10(root='./data', train=True, download=True)
x_train, y_train = cifar_trainset.data, torch.tensor(cifar_trainset.targets)
yy_train = torch.nn.functional.one_hot(y_train, num_classes=10)
print("CIFAR-10: ", x_train.shape, y_train.shape, yy_train.shape)


# # 아래의 데이터셋은 pytorch에 내장되어 있지 않음
# # Boston Housing 읽고 텐서 모양 출력
# (x_train,y_train),(x_test,y_test)=ds.boston_housing.load_data()
# print("Boston Housing: ",x_train.shape,y_train.shape)

# # Reuters 읽고 텐서 모양 출력
# (x_train,y_train),(x_test,y_test)=ds.reuters.load_data()
# print("Reuters: ",x_train.shape,y_train.shape)