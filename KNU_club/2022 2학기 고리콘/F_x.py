from sympy import Symbol, solve


def check(a, b, li):
    mid = (a + b) / 2
    num = 2 * n
    Sum = 0
    for i in range(n + 1):
        Sum += ((li[i] * (mid ** num)) * t)
        num -= 2
    return Sum


n = int(input())
a = list(map(float, input().split()))
x = Symbol('x')
num = 2 * n
equation = 0
result = 0
for i in range(n + 1):
    equation += a[i] * (x ** num)
    num -= 2
li = list(solve(equation))
x = li[0]
y = li[1]
k = int(input())
t = (y - x)/k

for i in range(k):
    result += check(x, x + t, a)
    x = x + t

print(abs(result))