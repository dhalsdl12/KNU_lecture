'''
07.
8-8.py에 교차 검증을 적용해 보다 신뢰성 높은 성능을 제시하시오. 
(k=3)교차 검증으로 측정한 정확률을 첨부하시오.
+7번 학습 시 epoch 값을 5으로 낮춰 적용하세요.
'''
import numpy as np
from tensorflow.keras.datasets import imdb
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense,LSTM,Embedding
from tensorflow.keras import preprocessing
from tensorflow.keras.callbacks import EarlyStopping

dic_siz=10000 # 사전의 크기(사전에 있는 단어 개수)
sample_siz=512 # 샘플의 크기
k = 3

# tensorflow가 제공하는 간소한 버전의 IMDB 읽기
(x_train,y_train),(x_test,y_test)=imdb.load_data(num_words=dic_siz)

embed_space_dim=16 # 16차원의 임베딩 공간

x_train=preprocessing.sequence.pad_sequences(x_train,maxlen=sample_siz)
x_test=preprocessing.sequence.pad_sequences(x_test,maxlen=sample_siz)

early=EarlyStopping(monitor='val_accuracy',patience=5,restore_best_weights=True)

fold_size = len(x_train) // k
accuracies = []

# 신경망 모델의 설계와 학습(LSTM 층 포함)
embed = Sequential()
embed.add(Embedding(input_dim=dic_siz, output_dim=embed_space_dim, input_length=sample_siz))
embed.add(LSTM(units=32))
embed.add(Dense(1, activation='sigmoid'))
embed.compile(loss='binary_crossentropy', optimizer='Adam', metrics=['accuracy'])

for fold in range(k):
    print(f"Training fold {fold+1}/{k}")

    # 검증 데이터셋 분할
    val_data = x_train[fold * fold_size: (fold + 1) * fold_size]
    val_labels = y_train[fold * fold_size: (fold + 1) * fold_size]

    # 학습 데이터셋 분할
    train_data = np.concatenate([x_train[:fold * fold_size], x_train[(fold + 1) * fold_size:]], axis=0)
    train_labels = np.concatenate([y_train[:fold * fold_size], y_train[(fold + 1) * fold_size:]], axis=0)

    hist = embed.fit(train_data, train_labels, epochs=5, batch_size=64, validation_data=(val_data, val_labels), verbose=2, callbacks=[early])

    # 모델 평가
    res = embed.evaluate(x_test, y_test, verbose=0)
    accuracies.append(res[1] * 100)

    print(f"Accuracy for fold {fold+1}: {accuracies[fold]}%")
    print("")

# 모델 평가
mean_accuracy = np.mean(accuracies)
print(f"평균 정확률 : {mean_accuracy}%")