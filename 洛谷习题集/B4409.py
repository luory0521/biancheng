x=int(input())
y=int(input())
n=int(input())
p=int(input())
if p >= x:
    y1=round(p-y,2)
    y2=round(p*(n/10),2)
    if y1 > y2:
        print("{:.2f}".format(y2))
    else:
        print("{:.2f}".format(y1))
elif p < x:
    print("{:.2f}".format(round(p*(n/10),2)))