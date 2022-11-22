N = int(input())
arr = [x for x in input().split()]
ans = []

min1 = arr[0][0]
min1i = 0
min1I = []
min2 = arr[0][1]
min2i = 0
min2I = []
min11 = '['
min22 = '['

for i in range(1, N):
    if min1 >= arr[i][0]:
        min1i = i
        min1 = arr[i][0]
    if min2 >= arr[i][1]:
        min2i = i
        min2 = arr[i][1]
print(min1, min2)

for i in range(0, N):
    if min1 == arr[i][0]:
        min1I.append(i)
        min1 = arr[i][0]
    if min2 == arr[i][1]:
        min2I.append(i)
        min2 = arr[i][1]

for i in range(0, N):
    if min11 >= arr[i][0] != min1:
        min11 = arr[i][0]
    if min22 >= arr[i][1] != min2:
        min22 = arr[i][1]
print(min11, min22)

for i in range(0, N):
    tmp = arr[i][0]
    tmp1 = arr[i][1]
    print(tmp, tmp1)
    if tmp >= min2:
        if min2 != tmp1:
            ans.append(tmp)
        elif len(min2I) > 1:
            ans.append(tmp)
        elif min22 != '[' and tmp > min22:
            ans.append(tmp)
    print(ans)
    if tmp1 >= min1:
        if min1 != tmp:
            ans.append(tmp1)
        elif len(min1I) > 1:
            ans.append(tmp1)
        elif min11 != '[' and tmp1 > min11:
            ans.append(tmp1)
    print(ans)

ans.sort()
print(ans)
le = 1
ans2 = []
ans2.append(ans[0])
for i in range(1, len(ans)):
    if ans[i] != ans[i - 1]:
        le += 1
        ans2.append(ans[i])
print(le)
for i in range(0, len(ans)):
    print(ans[i], end=' ')
