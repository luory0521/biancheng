n = int(input())
y = list(map(int, input().split()))
s = list(map(int, input().split()))
k = 0
for i in range(n - 1):
    ny = y[i]
    ns = s[i]
    xy = y[i + 1]
    xs = s[i + 1]
    lowy = min(ny, xy)
    bigy = max(ny, xy)
    lows = min(ns, xs)
    bigs = max(ns, xs)
    if lowy <= ns <= bigy or lowy <= xs <= bigy:
        k += 1
print(k)