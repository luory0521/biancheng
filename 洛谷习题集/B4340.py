minute=int(input())
hour=minute//60
minute=minute-hour*60
hourone=hour//10
hourtwo=hour%10
minuteone=minute//10
minutetwo=minute%10
print("|"+str(hourone)+"|"+str(hourtwo)+"|:|"+str(minuteone)+"|"+str(minutetwo)+"|")
#洛谷入门赛#36（https://www.luogu.com.cn/contest/251050）T1的测试点数据输入出现错误，请在洛谷语言入门月赛（2025 年 06 月）（https://www.luogu.com.cn/contest/251051#problems）T1进行重新作答