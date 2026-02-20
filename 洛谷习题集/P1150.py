n, k = map(int, input().split())
total = n
while n >= k:
    new = n // k
    total += new
    n = n % k + new
print(total)