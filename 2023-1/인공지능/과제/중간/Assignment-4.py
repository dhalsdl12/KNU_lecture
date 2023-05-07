from sklearn import datasets
from sklearn import svm, tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score, train_test_split
import numpy as np

digit = datasets.load_digits()
x_train, x_test, y_train, y_test = train_test_split(digit.data, digit.target,train_size=0.6) # 40%를 테스트 집합으로 함

################
# 본인 코드 작성
################
s = svm.SVC()
t = tree.DecisionTreeClassifier()
rf = RandomForestClassifier()

model = [s, t, rf]
scores = []
for m in model:
    score = np.mean(cross_val_score(m, digit.data, digit.target, cv=5))
    scores.append(score * 100)

print('훈련집합 정확률')
print('SVM : %0.2f' % (scores[0]))
print('결정트리 : %0.2f' % scores[1])
print('랜덤포레스트 %0.2f' % scores[2])
print()

best_idx = np.argmax(scores)
best = model[best_idx]
best.fit(x_train, y_train)
accuracy = best.score(x_test, y_test)

print('베스트 모델 : ', end='')
if best_idx == 0:
    print('SVM')
elif best_idx == 1:
    print('결정트리')
else:
    print('랜덤포레스트')

print('테스트집합 정확률 : %0.2f' % (accuracy * 100))
