#include <iostream>
using namespace std;

const int N = 1e4+10;

int primes[N],cnt=0;    // 用来存放所有质数
bool flag[N];           // 用来标记数i是合数还是质数，1为合数，0为质数

// 素数筛法，线性筛
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {   
        // i 为质数则进行标记
        if(!flag[i])primes[cnt++]=i;

        // 给当前数i乘上一个最小质因子pj
        for(int j=0;primes[j]<=n/i;j++)
        {
            flag[i*primes[j]]=1;
            // 此时的 pj 为 pj*i 的最小质因子了，我们不要更大的质因子来筛选 i 的倍数了，因为这样下去会重复筛选的，因此break
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    get_primes(10005);
    int res=0;
    for(int i=a;i<=b;++i)
    {
        if(i==1||flag[i])continue;
        int x=0,y=i;
        while(y)
        {
            x=x*10+y%10;
            y/=10;
        }
        if(flag[x])continue;
        res++;
    }
    cout<<res<<endl;
    return 0;
}