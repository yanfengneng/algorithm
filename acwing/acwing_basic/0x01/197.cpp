#include <iostream>
using namespace std;

const int N=1000010;

// cnt表示质数数量
int primes[N],cnt=0;
bool st[N];

// 素数线性筛法
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // i是素数，那么把这个质数存下来
        if(!st[i])primes[cnt++]=i;
        // 给当前数i乘上一个质因子
        for(int j=0;primes[j]*i<=n;j++)
        {
            // 标记为合数
            st[primes[j]*i]=true;
            // i有比prime[j]更小的质因子
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    get_primes(n);
    for(int i=0;i<cnt;++i)
    {
        int p=primes[i];

        int s=0,t=n;
        //这里就是N!中质因子p的个数，每次循环t/p表示下次循环p的次数+1
        while(t)s+=t/p,t/=p;
        printf("%d %d\n",p,s);
    }
    return 0;
}