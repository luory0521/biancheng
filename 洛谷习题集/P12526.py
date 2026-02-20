a,b,c=map(int,input().split())
p=a+b+c
if a==b and b==c and a==c:
    p=p+100
print(str(p))