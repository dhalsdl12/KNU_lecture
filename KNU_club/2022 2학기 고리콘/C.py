n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append([x, y])

a.sort()
x = a[0][0]
y = a[0][1]
Max = x + y
cnt = 1
for i in range(1, len(a)):
    if Max >= a[i][0]:
        xx = a[i][0]
        yy = a[i][1]
        Max = xx + yy
    else:
        x = a[i][0]
        y = a[i][1]
        Max = x + y
        cnt += 1

print(cnt)