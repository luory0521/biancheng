#include <iostream>
using namespace std;
int main()
{
	int all,books,every,ab,last;
	cout<<"题目：小明有16元，要买五本练习本，每本练习本3元钱，小明可以买几本练习本？还剩多少钱？"<<endl;
	cout<<"总共几元？"<<endl;
	cin>>all;
	cout<<"单价是几？"<<endl;
	cin>>every;
	cout<<"可以买"<<all/every<<"本。"<<endl;
	cout<<"还剩下"<<all%every<<"元。"<<endl;
	return 0;
}

