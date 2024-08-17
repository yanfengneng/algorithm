#include <iostream>
using namespace std;

int main()
{
    int a,b,p;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>a>>b>>p;
    int res=1%p;//最低位为1
    while(b){
        if(b&1)res=res*1ll*a%p;//ci为1，需要乘以a
        a=a*1ll*a%p;//每次a都平方
        b>>=1;
    }
    cout<<res<<endl;
    return 0;
}