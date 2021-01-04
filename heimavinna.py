import sys
data = sys.stdin.readline()

arr = data.split(';')

ans = 0

for part in arr:
    pos = part.find('-')
    if pos == -1:
        ans += 1
    else:
        start = int(part[:pos])
        end = int(part[pos+1:])
        ans += end - start + 1

print(ans)