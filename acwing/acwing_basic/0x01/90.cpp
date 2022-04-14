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
        //ci为1，需要进行相加，ci为0的话，是不用相加的
        if(b&1)res=(res+a)%p;
        //相邻项之间为2倍关系，指的是展开项中的相邻项
        a=a*2%p;//随时取余，避免溢出
        b>>=1;
    }
    cout<<res<<endl;
    return 0;
}