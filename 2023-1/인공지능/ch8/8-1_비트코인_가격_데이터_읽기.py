# 8-1(a) 비트코인 가격 데이터 읽기

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 코인데스크 사이트에서 다운로드한 1년치 비트코인 가격 데이터 읽기
f = open('BTC_USD_2019-02-28_2020-02-27-CoinDest.csv', 'r')
coindest_data = pd.read_csv(f, header=0)
seq = coindest_data[['Closing Price (USD)']].to_numpy()
print('데이터 길이 : ', len(seq), '\n앞쪽 5개 값 : ', seq[0:5])

# 그래프로 데이터 확인
plt.plot(seq, color='red')
plt.title('Bitcoin Prices (1 year from 2019-02-28)')
plt.xlabel('Days')
plt.ylabel('Price in USD')
plt.show()

# 8-1(b) 1년치 비트코인 가격 데이터를 윈도우로 자르기

# 시계열 데이터를 윈도우 단위로 자르는 함수
def seq2dataset(seq, window, horizon):
    X = []
    Y = []
    for i in range(len(seq) - (window + horizon) + 1):
        x = seq[i : (i + window)]
        y = (seq[i + window + horizon - 1])
        X.append(x)
        Y.append(y)
    
    return np.array(X), np.array(Y)

w = 2
h = 1

X, Y = seq2dataset(seq, w, h)
print(X.shape, Y.shape)
print(X[0], Y[0])
print(X[-1], Y[-1])