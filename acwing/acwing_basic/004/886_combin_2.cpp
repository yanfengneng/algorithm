#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, mod = 1e9+7;
// fact[i]表示i的阶乘；infact[i]表示i的阶乘的逆元
// a/b (mod p)  ≡ a * b^(p-2) (mod p)，也就是说 b 的模 m 的乘法逆元为 b^(m-2) (mod p)，可以使用快速幂来求逆元，因为是求 b^(m-2)
int fact[N],infact[N];

// 快速幂求 a^b (mod p)
// 所谓快速幂的快速在于将指数b分解成了二进制数表示，b= xk ... x1 x0，而代码实现的核心则是反复平方
// a^b = a^(2^xk+...2^x1+2^x0) = a^(2^xk) * ... * a^(2^x1) * a^(2^x0)，这样就把a^b分解成logb个数相乘了，其中相邻两项中后一项是前一项的平方
int qmi(int a,int b,int p)
{
    int res=1%p;
    while(b)
    {
        // 开始取b二进制数的末尾，若为1，则res需要乘上这一项
        // 这里首先判断b的二进制末尾是否为1，是因为a的指数幂是从a开始的
        if(b&1)res=1LL*res*a%p;
        // 然后移除二进制数的最后一位数字，方便下次枚举
        b>>=1;
        // 然后将当前a的指数幂进行平方，得到下一项的a的指数幂
        a=1LL*a*a%p;
    }
    return res;
}

// 初始化阶乘数组已经阶乘数组的逆元
void init()
{
    // 0 的阶乘为 1，以及 1 的逆元还是为 1
    fact[0]=infact[0]=1;
    // 求 i 的阶乘以及 i 的阶乘的逆元
    for(int i=1;i<N;++i){
        fact[i]=1LL*fact[i-1]*i%mod;
        // i 的逆元就是 i^(mod-2) 
        infact[i]=1LL*infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
}

int main()
{
    init();
    int n;scanf("%d",&n);
    while(n--)
    {
        int a,b;scanf("%d%d",&a,&b);
        // c[a][b]=a!/(b!*(a-b)!) 利用逆元将除法转换为乘法，得到fact[a]*infact[b]*infact[a-b]
        printf("%d\n",1LL*fact[a]*infact[a-b]%mod*infact[b]%mod);
    }
    return 0;
}