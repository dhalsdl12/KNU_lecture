import math

def get_primes(a, b):
    is_primes = [True] * b
    max_length = math.ceil(math.sqrt(b))

    for i in range(2, max_length):

        if is_primes[i]:

            for j in range(i + i, b, i):
                is_primes[j] = False

    return [i for i in range(a, b) if is_primes[i]]


a, b = map(int, input().split())
arr = []
if (a == 1):
    arr = get_primes(2, b + 1)
else:
    arr = get_primes(a, b + 1)

if len(arr) == 0:
    print(0)
else:
    bit = arr[0]
    for i in range(1, len(arr)):
        bit = bit^arr[i]
    print(bit)