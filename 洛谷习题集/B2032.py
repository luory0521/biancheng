a1,a2,n=map(int,input().split())
move=a2-a1
p=a1
for i in range(n-1):
    p+=move
print(p)
