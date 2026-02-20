s=float(input())
sd=2
ls=s
step=0
while ls > 0:
    ls = float(ls)-sd
    sd=sd*0.98
    step=step+1
print(f"{step:.0f}")