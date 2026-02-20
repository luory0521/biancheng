n=int(input())
p=list(map(int,input().split()))
pailie=True
for i in range(n-1):
    if p[i+1]!=p[i]+1:
        pailie=False
        break
if pailie:
    print("1")
else:
    jishu=0
    for i in range(n-1):
       if p[i+1]==p[i]+1:
          jishu=jishu+1
    print(str(n-jishu))
#得分55