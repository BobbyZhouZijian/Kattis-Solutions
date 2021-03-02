import sys
from functools import lru_cache
sys.setrecursionlimit(10000000)

arr = sys.stdin.readlines()

TC = int(arr[0])

a = [0 for _ in range(25)]
b = [0 for _ in range(25)]
n = 0
c = 0
d = 0

@lru_cache(maxsize=None)
def search(x, y):
    if x <= 0 or y <= 0:
        return d

    res = c
    for i in range(n):
        res += search(x-a[i], y- b[i])

    return res 

for i in range(TC):
    cur = arr[2*i+1].split(' ')
    n = len(cur)//2-1
    for j in range(n):
        a[j] = int(cur[2*j])
        b[j] = int(cur[2*j+1])

    c = int(cur[-2])
    d = int(cur[-1])
    
    cur2 = arr[2*i+2].split(' ')
    search.cache_clear()
    for j in range(0, len(cur2), 2):
        print(search(int(cur2[j]), int(cur2[j+1])))
    print('\n')
