n, k, r, q = map(int, input().split())
T = {}
li = []
result = []
pre_i = 0
for a in range(k):
    li.append(list(map(int, input().split())))
li.sort()
for a in range(k):
    i, x, y = li[a]
    if a != 0:
        if T[pre_i][1] == y:
            for aa in range(i - 1 - pre_i):
                T[pre_i + aa + 1] = [T[pre_i][0] + aa + 1, y, 'x']
                if len(T) == n:
                    break
            if a == k - 1:
                T[i] = [x, y, '0']
                break
            T[i] = [x, y, 'y']
        else:
            for aa in range(i - 1 - pre_i):
                T[pre_i + aa + 1] = [x, T[pre_i][1] + aa + 1, 'y']
                if len(T) == n:
                    break
            if a == k - 1:
                T[i] = [x, y, '0']
                break
            T[i] = [x, y, 'x']
    elif a == 0:
        T[i] = [x, y, '0']
    pre_i = i


for i in range(q):
    j, x, y = map(int, input().split())
    a, b, c = T[j]
    dis = ((x - a) ** 2 + (y - b) ** 2) ** 0.5
    if dis > r:
        result.append('gori')
    elif dis <= r:
        if c == '0' and j == 1:
            if T[1][0] == T[2][0]:
                c = 'y'
            else:
                c = 'x'
        elif c == '0' and j == n:
            if T[n][0] == T[n - 1][0]:
                c = 'y'
            else:
                c = 'x'
            print(c)
        if c == 'x':
            if y < b:
                result.append('unsafe')
            elif y > b:
                result.append('safe')
            else:
                result.append('gori')
        elif c == 'y':
            if x > a:
                result.append('unsafe')
            elif x < a:
                result.append('safe')
            else:
                result.append('gori')
for re in result:
    print(re)