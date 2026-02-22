#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int num=1;
    while(n--){
        if(a[num]%10>=5)
            cout<<a[num]-(a[num]%10)+10<<endl;
        else 
            cout<<a[num]-(a[num]%10)<<endl;
        num++;
    }
    return 0;
}
