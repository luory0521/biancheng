#include <bits/stdc++.h> 
using namespace std;
int main(){
	for(int x=0;x<=36;x++){
		for(int y=0;y<=36;y++){
			for(int z=0;z<=36;z++){
				if((600*x+400*y+250*z)==10050&&(x+z+y)==36){
					cout<<x<<" "<<y<<" "<<z;
					cout<<endl;
				}
			}
		}
	}
}
