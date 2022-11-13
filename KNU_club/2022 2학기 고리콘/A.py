n = int(input())
result = []
for i in range(n):
    money = []
    Sum = 0
    m = int(input())
    k, d, a = 0, 0, 0
    for j in range(m):
        x, y, z = map(int, input().split())
        money.append([x, y, z])
    q, w, e = map(int, input().split())

    for x, y, z in money:
        kkk = q*x - w*y + e*z
        if kkk < 0:
            continue
        Sum += kkk
    result.append(Sum)
for re in result:
    print(re)