#include <iostream>
using namespace std;

int main()
{
    int a,b,p;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>a>>b>>p;
    int res=1%p;//���λΪ1
    while(b){
        if(b&1)res=res*1ll*a%p;//ciΪ1����Ҫ����a
        a=a*1ll*a%p;//ÿ��a��ƽ��
        b>>=1;
    }
    cout<<res<<endl;
    return 0;
}