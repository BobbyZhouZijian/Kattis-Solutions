import sys

MAX_N = 1000010
p = 131
M = 10**18+9
Pow = [0] * MAX_N
h = [0] * MAX_N

def computeRollingHash(T):
  n = len(T)

  Pow[0] = 1
  for i in range(1, n):
    Pow[i] = (Pow[i-1]*p) % M
  h[0] = 0
  for i in range(n):
    if i != 0:
      h[i] = h[i-1];
    h[i] = (h[i] + (ord(T[i])*Pow[i]) % M) % M


def extEuclid(a, b):
  xx, yy = 0, 1
  x, y = 1, 0
  while b != 0:
    q = a//b
    a, b = b, a%b
    x, xx = xx, x-q*xx
    y, yy = yy, y-q*yy
  return a, x, y


def modInverse(b, m):
  d, x, y = extEuclid(b, m)
  if d != 1:
    return -1
  return (x+m)%m


def hash_fast(L, R):
  if R < L:
    return 0
  if L == 0:
    return h[R]
  ans = ((h[R] - h[L-1]) % M + M) % M
  ans = (ans * modInverse(Pow[L], M)) % M
  return ans


n = int(input())
hashes = set()
new_h = {}

for i in range(n):
    s = sys.stdin.readline()[:-1]
    computeRollingHash(s)
    h0 = hash_fast(0,len(s)-1)
    hashes.add(h0)
    new_h[s] = []
    for i in range(len(s)):
        h1 = (hash_fast(0,i-1) + hash_fast(i+1,len(s)-1) * Pow[i]) % M
        new_h[s].append(h1)

work = False
for s, arr in new_h.items():
    found = False
    for h in arr:
        if found:
            break
        if h in hashes:
            print(s)
            found = True
            work = True

if not work:
    print("NO TYPOS")

