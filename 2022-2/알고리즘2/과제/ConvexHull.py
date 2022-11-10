import math


def grahamScan(points):
    def ccw(i, j, k):
        area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
        if area2 > 0:
            return True
        else:
            return False

    answer = []
    p = []
    points.sort(key=lambda x: (x[1], -x[0]))
    answer.append(points[0])
    p.append([0, points[0]])
    for i in range(1, len(points)):
        a = math.atan2(points[i][1] - points[0][1], points[i][0] - points[0][0])
        p.append([a, points[i]])
    p.sort(key=lambda x: x[0])
    for i in range(1, len(points)):
        point = p[i][1]
        if i == 1:
            answer.append(point)
        else:
            jj = answer.pop()
            ii = answer.pop()
            while True:
                if ccw(ii, jj, point):
                    answer.append(ii)
                    answer.append(jj)
                    answer.append(point)
                    break
                else:
                    jj = ii
                    ii = answer.pop()
    return answer


if __name__ == "__main__":
    print(grahamScan([(0, 0), (-2, -1), (-1, 1), (1, -1), (3, -1), (-3, -1)]))
    print(grahamScan([(4, 2), (3, -1), (2, -2), (1, 0), (0, 2), (0, -2), (-1, 1),
                      (-2, -1), (-2, -3), (-3, 3), (-4, 0), (-4, -2), (-4, -4)]))
    print(grahamScan([(4, 2), (3, -1), (2, -2), (1, 0), (0, 2), (0, -2), (-1, 1),
                      (-2, -1), (-2, -3), (-3, 3), (-4, 0), (-4, -2), (-4, -4), (0, -3)]))
