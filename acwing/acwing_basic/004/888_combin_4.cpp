#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int primes[N],cnt=0;
// v[i] 记录数字 i 为素数还是合数，v[i]=true时 i 为合数，否则 i 为素数
bool v[N];
// sum[i]=c 表示质数 i 的个数为 c
int sum[N];

// 线性筛法
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // i为质数，则存在primes中
        if(!v[i])primes[cnt++]=i;
        // 给当前数i乘上一个质因子pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            v[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

// 计算 n 里面含有质数 p 的个数，这里的计算是不重不漏的。
// p^k的倍数会被计算k次：第一次算p的倍数时，被加一次；第二次算p^2的倍数时，被加一次；第三次算p^3的倍数时，被加一次...第k次算p^k的倍数时，被加一次。总共被加了k次，是不重不漏的。
int get(int n,int p)
{
    int res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

// A * b：把 b 看成一个整体，然后与 A 中每一位相乘，A中的数字采用小端存储，即低位数字存储在数组的前面，高位数字存储在数组的后面
vector<int> mul(const vector<int>& A,const int b)
{
    if(b==0)return {0};
    vector<int> res;
    // t 表示乘法进位，这里的进位不限于0 1，可以为任意数字
    for(int i=0,t=0,n=A.size();i<n||t>0;++i)
    {
        // 获得当前位的乘积和
        if(i<n)t+=A[i]*b;
        // 添加个位数字
        res.push_back(t%10);
        // 保留进位
        t/=10;
    }

     // 如 1234 * 0 = 0000，需要删除前导0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    int a,b;cin>>a>>b;

    // 将 a 分解质因数
    get_primes(a);

    for(int i=0;i<cnt;++i)
    {
        // 当前的质数为 p
        int p=primes[i];
        // 用分子里面 p 的个数减去分母里面 p 的个数。这里的计算组合数的公式为a!/(b!*(a-b)!)，因此用 a 里面 p 的个数减去 b 里面 p 的个数和 (a-b) 里面 p 的个数。
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);
    }

    // 使用高精度乘法把所有质因子乘到一块去就好了
    vector<int> res={1};
    for(int i=0;i<cnt;++i)
        // res*p^k，这里是k个p相乘，不是k*p，所以需要使用一个循环
        for(int j=0;j<sum[i];++j)
            res=mul(res,primes[i]);
    
    // 倒序打印 res 即可，由于采用小端存储，所以高位在后，从后往前打印即可
    for(int i=res.size()-1;i>=0;i--)printf("%d",res[i]);
    return 0;
}