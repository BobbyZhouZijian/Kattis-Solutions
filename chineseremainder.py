import sys
from functools import reduce

def chinese_remainder(n, a):
    sum=0
    prod=reduce(lambda a, b: a*b, n)
    for n_i, a_i in zip(n,a):
        p=prod//n_i
        sum += a_i* mul_inv(p, n_i)*p
    return sum % prod

def mul_inv(a, b):
    b0= b
    x0, x1= 0,1
    if b== 1: return 1
    while a>1 :
        q=a// b
        a, b= b, a%b
        x0, x1=x1 -q *x0, x0
    if x1<0 : x1+= b0
    return x1

arr = sys.stdin.readlines()

t = int(arr[0])

for i in range(1,t+1):
    r = [int(x) for x in arr[i].split(' ')]
    x = chinese_remainder([r[1],r[3]], [r[0],r[2]]) 
    print(x, r[1]*r[3])
