n=int(input())
s=str(input())
t=str(input())
def fenge(a, meige):
    return [a[i:i+meige] for i in range(0,len(a),meige)]
sl=fenge(s,1)
tl=fenge(t,1)
if (sorted(sl)==sorted(tl)) == True:
    print("Yes")
else :
    print("No")