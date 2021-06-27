n = int(input())
arr = [x for x in input().split()]
ans = []

for i in range(n):
    for j in range(i+1, n):
        if i != j:
            if arr[i][0] >= arr[j][1]:
                ans.append(arr[i][0])
            else:
                ans.append(arr[j][1])
            if arr[i][1] >= arr[j][0]:
                ans.append(arr[i][1])
            else:
                ans.append(arr[j][0])
ans = list(set(ans))
ans.sort()
print(len(ans))
for i in range(len(ans)):
    print(ans[i], end=" ")