n, k = map(int, input().split())
cnt = 0
check = 0
arr = list(map(int, input().split()))

for i in range(n):
    if arr[i] == 1:
        if cnt == 0:
            check = 1
        elif i == 0:
            if arr[-1] == 1:
                check = 1
        elif arr[i - 1] == 1:
            check = 1
        elif i == n-1:
            if arr[0] == 1:
                check = 1
    if check == 1:
        cnt += 1
        check = 0

if cnt >= k:
    print("고리!")
else:
    print("고리!가 아님")
