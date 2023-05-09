from sklearn.datasets import fetch_openml
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt
import numpy as np

# MNIST 데이터셋을 읽고 훈련 집합과 테스트 집합으로 분할
mnist = fetch_openml('mnist_784')
mnist.data = mnist.data/255.0
x_train = mnist.data[:60000]; x_test = mnist.data[60000:]
y_train = np.int16(mnist.target[:60000]); y_test = np.int16(mnist.target[60000:])

################
# 본인 코드 작성
################
mlp = MLPClassifier(hidden_layer_sizes=(100),learning_rate_init=0.001,
                  batch_size=512,max_iter=300,solver='adam',verbose=True)
mlp.fit(x_train,y_train)
res = mlp.predict(x_test)

conf=np.zeros((10,10),dtype=np.int16)
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("(은닉층 1개)테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")



mlp = MLPClassifier(hidden_layer_sizes=(100, 100),learning_rate_init=0.001,
                  batch_size=512,max_iter=300,solver='adam',verbose=True)
mlp.fit(x_train,y_train)
res = mlp.predict(x_test)

conf=np.zeros((10,10),dtype=np.int16)
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("(은닉층 2개)테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")



mlp = MLPClassifier(hidden_layer_sizes=(100, 100, 100),learning_rate_init=0.001,
                  batch_size=512,max_iter=300,solver='adam',verbose=True)
mlp.fit(x_train,y_train)
res = mlp.predict(x_test)

conf=np.zeros((10,10),dtype=np.int16)
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("(은닉층 3개)테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")



mlp = MLPClassifier(hidden_layer_sizes=(100, 100, 100, 100),learning_rate_init=0.001,
                  batch_size=512,max_iter=300,solver='adam',verbose=True)
mlp.fit(x_train,y_train)
res = mlp.predict(x_test)

conf=np.zeros((10,10),dtype=np.int16)
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("(은닉층 4개)테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")



mlp = MLPClassifier(hidden_layer_sizes=(100, 100, 100, 100, 100),learning_rate_init=0.001,
                  batch_size=512,max_iter=300,solver='adam',verbose=True)
mlp.fit(x_train,y_train)
res = mlp.predict(x_test)

conf=np.zeros((10,10),dtype=np.int16)
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("(은닉층 5개)테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")