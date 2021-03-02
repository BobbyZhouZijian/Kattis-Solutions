import sys
import math

arr = sys.stdin.readlines()

n = int(arr[0])
nums = [int(x) for x in arr[1].split(' ')]


mod = 1000000007
i = 1

work= True

for num in nums:
    i *= 2
    if (num > i):
        work = False
        break
    i -= num

if work:
    print(i % mod)
else:
    print("error")