n = int(input())

arr = list(range(1, 10))

for i in range(2, n+1):
    add = []
    for j in range(0, 10):
        for k in arr:
            newk = k * 10 + j;
            if newk % i == 0:
                add.append(newk)
    arr = add


print(len(arr))

