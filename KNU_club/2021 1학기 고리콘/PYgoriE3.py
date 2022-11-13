n = int(input())
arr = [x for x in input().split()]
ans = []

for i in range(1, n):
        if arr[0][0] >= arr[i][1]:
            if arr[0][0] not in ans:
                ans.append(arr[0][0])
        else:
            if arr[i][1] not in ans:
                ans.append(arr[i][1])
        if arr[0][1] >= arr[i][0]:
            if arr[0][1] not in ans:
                ans.append(arr[0][1])
        else:
            if arr[i][0] not in ans:
                ans.append(arr[i][0])
for i in range(2, n):
        if arr[1][0] >= arr[i][1]:
            if arr[1][0] not in ans:
                ans.append(arr[1][0])
        else:
            if arr[i][1] not in ans:
                ans.append(arr[i][1])
        if arr[1][1] >= arr[i][0]:
            if arr[1][1] not in ans:
                ans.append(arr[1][1])
        else:
            if arr[i][0] not in ans:
                ans.append(arr[i][0])
ans.sort()
print(len(ans))
for i in range(len(ans)):
    print(ans[i], end=" ")