print("欢迎使用简单数学运算程序")
while True:
    print("\n请选择运算类型：1.加法 2.减法 3.乘法 4.除法 5.退出")
    choice = input("输入选项数字：")
    if choice == '5':
        print("程序退出，再见！")
        break     
    if choice not in {'1', '2', '3', '4'}:
        print("输入错误，请重新选择")
        continue
    try:    
        num1 = float(input("请输入第一个数字："))
        num2 = float(input("请输入第二个数字："))
        if choice == '1':
            result = num1 + num2
            op = '+'
        elif choice == '2':
            result = num1 - num2
            op = '-'
        elif choice == '3':
            result = num1 * num2
            op = '*'
        else:
            if num2 == 0:
                print("错误：除数不能为0！")
                continue
            result = num1 / num2
            op = '/'
        print(f"{num1} {op} {num2} = {result:.2f}")
    except ValueError:
        print("错误：计算的内容必须是数字")