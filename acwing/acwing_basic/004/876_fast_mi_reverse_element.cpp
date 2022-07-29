#include <bits/stdc++.h>
using namespace std;

// a^b mod p
// 所谓快速幂的快速在于将指数b分解成了二进制数表示，b= xk ... x1 x0，而代码实现的核心则是反复平方
// a^b = a^(2^xk+...2^x1+2^x0) = a^(2^xk) * ... * a^(2^x1) * a^(2^x0)，这样就把a^b分解成logb个数相乘了，其中相邻两项中后一项是前一项的平方
int power(int a,int b,int p)
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

int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        // 逆元公式推导：a/b ≡ a*x (mod m)；等式两边同时乘 b，得：b*a/b ≡ a*b*x (mod m)，化简得：a ≡ a*b*x (mod m)
        // 所以 b*x ≡ 1 (mod m)，由费马小定理，b^(m-1) ≡ 1 (mod m) 其中 m 为质数。联系本方程 b * b^(m-2) ≡ 1，所以 b 的逆元 x 为 b^(m-2)；
        // 若 b 是 m 的倍数，则无解的，因为 b 是 m 的倍数，那么 b*x 也必定是 m 的倍数，模 m 的余数为 0，必定不为 1，是无解的情况。
        // 若 b 不是 m 的倍数，由于 m 是质数，那么 b 与 m 是互质的，由费马小定理可知，b^(m-1) ≡ 1 (mod m)，一定存在逆元，一定有解。
        int b,m;scanf("%d%d",&b,&m);
        // b 是 m 的倍数时，是无解的
        if(b%m==0)puts("impossible");
        // 否则 b 的逆元是 b^(m-2)%m
        else printf("%d\n",power(b,m-2,m));
    }
    return 0;
}