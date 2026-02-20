yd=int(input())
if yd <= 150:
    p=yd*0.4463
    print(f"{p:.1f}")
elif yd > 150 and yd <= 400:
    p=150*0.4463+(yd-150)*0.4663
    print(f"{p:.1f}")
elif yd >= 401:
    p=150*0.4463+250*0.4663+(yd-400)*0.5663
    print(f"{p:.1f}")