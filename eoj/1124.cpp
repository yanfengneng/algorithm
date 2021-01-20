#include <bits/stdc++.h>
using namespace std;

int power(int a,int b,int p)
{
    int res=1%p;// 最低位为1
    while(b){
        if(b&1)res=res*1ll*a%p;// ci为1，需要乘以a
        a=a*1ll*a%p;// 每次a都平方
        b>>=1;
    }
    return res;
}

int main()
{
    int a,b,c;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)break;
        else printf("%d",power(a,b,c));
    }
    return 0;
}