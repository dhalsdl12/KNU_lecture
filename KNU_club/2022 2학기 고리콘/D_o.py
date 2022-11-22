import sys, bisect

n, k, r, q = map(int, input().split())
arr = []
arr2 = []
answer = []
for _ in range(k):
    arr.append(list(map(int, input().split())))
for i in arr:
    arr2.append(i[0])
for i in range(q):
    tmp = list(map(int, input().split()))
    idx = bisect.bisect_left(arr2, tmp[0])
    state = ""
    if arr2[idx] == tmp[0] and tmp[0] != n:
        if arr[idx][1] == arr[idx + 1][1]:
            x = arr[idx][1]
            if arr[idx][2] < arr[idx + 1][2]:
                y = arr[idx][2] + (tmp[0] - arr[idx][0])
                state = "y+"
            else:
                y = arr[idx][2] - (tmp[0] - arr[idx][0])
                state = "y-"
        else:
            y = arr[idx][2]
            if arr[idx][1] < arr[idx + 1][1]:
                x = arr[idx][1] + (tmp[0] - arr[idx][0])
                state = "x+"
            else:
                x = arr[idx][1] - (tmp[0] - arr[idx][0])
                state = "x-"

    else:
        if arr[idx - 1][1] == arr[idx][1]:
            x = arr[idx - 1][1]
            if arr[idx - 1][2] < arr[idx][2]:
                y = arr[idx - 1][2] + (tmp[0] - arr[idx - 1][0])
                state = "y+"
            else:
                y = arr[idx - 1][2] - (tmp[0] - arr[idx - 1][0])
                state = "y-"
        else:
            y = arr[idx - 1][2]
            if arr[idx - 1][1] < arr[idx][1]:
                x = arr[idx - 1][1] + (tmp[0] - arr[idx - 1][0])
                state = "x+"
            else:
                x = arr[idx - 1][1] - (tmp[0] - arr[idx - 1][0])
                state = "x-"
    x_d = tmp[1] - x
    y_d = tmp[2] - y
    if (x_d ** 2 + y_d ** 2) ** 0.5 > r or ((state == 'y+' or state == 'y-') and x_d == 0) or\
            ((state == 'x+' or state == 'x-') and y_d == 0):
        answer.append("gori")
    elif state == 'y+':
        if x_d < 0:
            answer.append("safe")
        else:
            answer.append("unsafe")
    elif state == 'y-':
        if x_d > 0:
            answer.append("safe")
        else:
            answer.append("unsafe")
    elif state == 'x+':
        if y_d > 0:
            answer.append("safe")
        else:
            answer.append("unsafe")
    elif state == 'x-':
        if y_d < 0:
            answer.append("safe")
        else:
            answer.append("unsafe")
for ans in answer:
    print(ans)