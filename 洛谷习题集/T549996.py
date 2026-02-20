x,y,a,z=map(int,input().split())
if y > a:
    print(str(a*x))
else:
    yj=a*x
    g=(a+y-1)//y
    cx=g*z
    print(str(min(yj,cx)))