n, k = map(int, input().split())

arr = list(map(int, input().split()))

for i in range(n):
    if i == 0:
        continue
    if(arr[i] != 0):
        if arr[i-1] != 0:
            arr[i] += arr[i-1]

max = 0
for i in range(n):
    if max < arr[i]:
        max = arr[i]

if arr[n-1] != 0:
    for i in range(n):
        if arr[i] != 0:
            continue
        elif arr[i] == 0:
            arr[n-1] += arr[i-1]
            break

for i in range(n):
    if max < arr[i]:
        max = arr[i]

if max >= k:
    print("고리!")
else:
    print("고리!가 아님")