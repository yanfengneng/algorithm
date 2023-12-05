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
    int n;
    // 输入数据量较大，所以尽量使用c语言的输入输出
    scanf("%d",&n);
    while(n--)
    {
        int a,b,p;scanf("%d%d%d",&a,&b,&p);
        printf("%d\n",power(a,b,p));
    }
    return 0;
}