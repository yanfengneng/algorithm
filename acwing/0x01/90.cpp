#include <iostream>
using namespace std;

int main()
{
    long long a,b,p;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>a>>b>>p;
    long long res=0;
    while(b){
        //ciΪ1����Ҫ������ӣ�ciΪ0�Ļ����ǲ�����ӵ�
        if(b&1)res=(res+a)%p;
        //������֮��Ϊ2����ϵ��ָ����չ�����е�������
        a=a*2%p;//��ʱȡ�࣬�������
        b>>=1;
    }
    cout<<res<<endl;
    return 0;
}