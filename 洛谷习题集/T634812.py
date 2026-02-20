n,a,b=map(int,input().split())
if a * n > b or a * n == b:
    print(str(b))
elif a * n < b:
    print(str(a*n))