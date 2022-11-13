n = int(input())

dic = {}
Max = 0
Min = 9999999
answer = []
for i in range(n):
    str = input()
    Max = max(Max, len(str))
    Min = min(Min, len(str))
    dic[str] = 0
for i in range(n):
    str = input()
    Max = max(Max, len(str))
    Min = min(Min, len(str))
    dic[str] = 1

n = int(input())
for i in range(n):
    result = 0
    str = input()
    st = ''
    for i in range(len(str)):
        for j in range(Min, Max + 1):
            if i + j > len(str):
                continue
            st = str[i:i + j]
            if st in dic:
                if dic[st] == 0:
                    result -= 1
                else:
                    result += 1
    answer.append(result)

for ans in answer:
    if ans < 0:
        print("HIGH", -ans)
    elif ans > 0:
        print("LOW", ans)
    else:
        print("GOOD")
