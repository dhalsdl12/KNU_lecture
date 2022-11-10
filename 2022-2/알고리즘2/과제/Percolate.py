import random
import statistics
import math


def simulate(N, T):
    def root(i):
        while i != ids[i]:
            i = ids[i]
        return i

    def connected(p, q):
        return root(p) == root(q)

    def union(p, q):
        id1, id2 = root(p), root(q)
        if id1 == id2:
            return
        if size[id1] <= size[id2]:
            ids[id1] = id2
            size[id2] += size[id1]
        else:
            ids[id2] = id1
            size[id1] += size[id2]

    number = []
    first = N * N
    last = N * N + 1
    for c in range(T):
        cnt = 0
        idx = []
        ids, size, oc = [], [], []
        for i in range(N * N):
            idx.append(i)
        random.shuffle(idx)

        for i in range(N * N + 2):
            ids.append(i)
            size.append(1)
            oc.append(0)

        while True:
            a = idx.pop()
            if a % N != 0 and oc[a - 1] == 1:
                union(a, a - 1)
            if (a + 1) % N != 0 and oc[a + 1] == 1:
                union(a, a + 1)
            if a - N >= 0 and oc[a - N] == 1:
                union(a, a - N)
            if a + N < N * N and oc[a + N] == 1:
                union(a, a + N)
            oc[a] = 1
            cnt += 1
            if 0 <= a < N:
                union(first, a)
            if N * N - N <= a < N * N:
                union(last, a)

            if connected(first, last):
                number.append(cnt / (N * N))
                break
    mean = statistics.mean(number)
    stdev = statistics.stdev(number)
    a = mean - 1.96 * stdev / math.sqrt(T)
    b = mean + 1.96 * stdev / math.sqrt(T)
    print("mean                    = {:.10f}".format(mean))
    print("stdev                   = {:.10f}".format(stdev))
    print("95% confidence interval = [{:.10f}, {:.10f}]".format(a, b))
    return mean, stdev
