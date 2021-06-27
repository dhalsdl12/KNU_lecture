n, m = map(int, input().split())
arr = [[int(x) for x in input().split()]for y in range(n)]
x, y = map(int, input().split())
queue = list()
visit = list()
cnt = 0
queue.append([x, y])

while queue:
    node = queue.pop(0)
    a = int(node[0])
    b = int(node[1])
    if arr[a][b] != 0:
        if node not in visit:
            visit.append(node)
            if node[0] != 0:
                queue.append([node[0]-1, node[1]])
            if node[1] != m-1:
                queue.append([node[0], node[1]+1])
            if node[0] != n-1:
                queue.append([node[0]+1, node[1]])
            if node[1] != 0:
                queue.append([node[0], node[1]-1])
            cnt += 1

print(cnt-1)