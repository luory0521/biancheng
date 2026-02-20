#include <iostream>
using namespace std;
int main()
{
    int a1, a2, a3, a4, a5;
    cout << "请输入5个整数" << endl;
    cout << "第一个数" << endl;
    cin >> a1;
    cout << "第二个数" << endl;
    cin >> a2;
    cout << "第三个数" << endl;
    cin >> a3;
    cout << "第四个数" << endl;
    cin >> a4;
    cout << "第五个数" << endl;
    cin >> a5;
    if (a2 - a1 == a3 - a2 && a4 - a3 == a3 - a2 && a5 - a4 == a4 - a3)
        cout << "是等差数列，公差为" << a5 - a4 << endl;
    else
        cout << "不是等差数列" << endl;
    return 0; 
}
