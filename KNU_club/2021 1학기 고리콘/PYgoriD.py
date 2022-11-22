a, b = map(int, input().split())

arr = []
for i in range(a, b + 1):
    count = 0

    for k in range(1, i + 1):
        if i % k == 0:
            count += 1
    if count <= 2:
        arr.append(i)

bit = arr[0]

for i in range(1, len(arr)):
    bit = bit ^ arr[i]

print(bit)