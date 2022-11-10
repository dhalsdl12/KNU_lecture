def collinearPoints(points):
    def check(a, b):
        if b[1] - a[1] == 0:
            return 0
        elif b[0] - a[0] == 0:
            return float('inf')
        else:
            return (b[1] - a[1]) / (b[0] - a[0])

    answer = []
    points.sort(key=lambda x: (x[0], x[1]))
    for i in range(len(points)):
        li = []
        for j in range(len(points)):
            if i != j:
                li.append([points[j][0], points[j][1], check(points[i], points[j])])
        li.sort(key=lambda x: x[2])
        cnt = 0
        cur = li[0][2]
        for j in range(1, len(li)):
            if li[j][2] == cur:
                cnt += 1
                if j == len(li) - 1 and cnt >= 2:
                    ans = [[points[i][0], points[i][1]], [li[j][0], li[j][1]], [li[j - cnt][0], li[j - cnt][1]]]
                    ans.sort(key=lambda x: (x[0], x[1]))
                    ans2 = (ans[0][0], ans[0][1], ans[2][0], ans[2][1])
                    if ans2 not in answer:
                        answer.append(ans2)
            else:
                if cnt >= 2:
                    # j번째는 동일하지 않기때문에 j-1
                    ans = [[points[i][0], points[i][1]], [li[j - 1][0], li[j - 1][1]], [li[j - 1 - cnt][0], li[j - 1 - cnt][1]]]
                    ans.sort(key=lambda x: (x[0], x[1]))
                    ans2 = (ans[0][0], ans[0][1], ans[2][0], ans[2][1])
                    if ans2 not in answer:
                        answer.append(ans2)
                cnt = 0
                cur = li[j][2]

    return answer


if __name__ == "__main__":
    print(collinearPoints([(19000, 10000), (18000, 10000), (32000, 10000), (21000, 10000), (1234, 5678), (14000, 10000)]))
    print(collinearPoints([(10000, 0), (0, 10000), (3000, 7000), (7000, 3000), (20000, 21000), (3000, 4000), (14000, 15000), (6000, 7000)]))
    print(collinearPoints([(0, 0), (1, 1), (3, 3), (4, 4), (6, 6), (7, 7), (9, 9)]))
    print(collinearPoints([(1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0), (8, 0)]))
    print(collinearPoints([(7,0), (14,0), (22,0), (27,0), (31,0), (42,0)]))
    print(collinearPoints([(12446, 18993), (12798, 19345), (12834, 19381), (12870, 19417), (12906, 19453), (12942, 19489)]))
    print(collinearPoints([(1, 1), (2, 2), (3, 3), (4, 4), (2, 0), (3, -1), (4, -2), (0, 1), (-1, 1), (-2, 1), (-3, 1), (2, 1), (3, 1), (4, 1), (5, 1)]))
