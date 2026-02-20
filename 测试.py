x, n = map(int, input().split())
f = 0
for i in range(n):
    c = x + (i - 1) % 7 + 1
    if c < 6:
        f += 250
print(f)