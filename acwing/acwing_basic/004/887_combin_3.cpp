#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int qmi(int a,int b,int p)
{
    int res=1%p;
    while(b)
    {
        if(b&1)res=1LL*res*a%p;
        a=1LL*a*a%p;
        b>>=1;
    }
    return res;
}

// 计算c[a][b]
int C(int a,int b,int p)
{
    // b>a 就不用计算阶乘了，直接返回 0
    if(b>a)return 0;
    int res=1;
    // c[a][b] = a*(a-1)*...(a-b+1) / b!，除法转换为乘法逆元 b^(p-2) (mod p)
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=1LL*res*j%p;
        res=1LL*res*qmi(i,p-2,p)%p;
    }
    return res;
}

int lucas(LL a,LL b,int p)
{
    // 只有 a b 都小于 p 时，就不能用继续用卢卡斯定理了，直接返回阶乘即可
    if(a<p&&b<p)return C(a,b,p);
    return 1LL*C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}

int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        LL a,b;int p;
        scanf("%ld%ld%d",&a,&b,&p);
        printf("%d\n",lucas(a,b,p));
    }
    return 0;
}