n, m, q = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

for i in range(q):
    li = list(map(int, input().split()))
    num = len(li)
    if num == 3:
        tmp1 = arr[li[1]]
        tmp2 = arr[li[2]]
        arr[li[1]] = tmp2
        arr[li[2]] = tmp1
    elif num == 4:
        arr[li[1]][li[2]] = li[3]

for ar in arr:
    for a in ar:
        print(a, end=' ')
    print()
