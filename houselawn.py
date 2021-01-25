import sys

arr = sys.stdin.readlines()
l, m = arr[0].split(' ')

l = int(l)

res = []
for i in range(1, len(arr)):
    cur = arr[i].split(',')
    n = len(cur)
    name = cur[n-5]
    p = int(cur[n-4])
    c = int(cur[n-3])
    t = int(cur[n-2])
    r = int(cur[n-1])

    rate = float(c*t) * 10080.0 / float(t+r)
    if rate + 1e-9 > l:
        res.append([name, p])

if len(res) == 0:
    print("no such mower")
else:
    cheap = 100000000
    for i in res:
        cheap = min(cheap, i[1])
    for i in res:
        if i[1] == cheap:
            print(i[0])
