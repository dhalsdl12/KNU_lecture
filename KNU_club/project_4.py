row = int(input("size : "))

for x in range(1, row, 1):
    print(" "*(row-x) + "*"*(2*x-1))
for x in range(row, 0, -1):
    print(" "*(row-x) + "*"*(2*x-1))