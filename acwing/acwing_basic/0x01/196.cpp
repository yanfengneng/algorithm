#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=1000010;

// primes用来存放素数，cnt用来统计素数的个数
// st用来标记是素数还是合数，0表示素数，1表示合数
int primes[N],cnt=0;
bool st[N];

// 素数线性筛法
void get_primes(int n)
{
    // 由于有lr，因此每次都要重新计算素数
    memset(st,false,sizeof st);
    cnt=0;
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
    long long l,r;
    while(cin>>l>>r)
    {
        // 一个合数N必定包含一个不超过sqrt(N)的质因子，sqrt(2^31-1)=4w多~~=5w
        get_primes(50000);

        //计算完50000内的所有质数之后，在将st还原，将[2,sqrt(r)]内的质数p的倍数标记为合数
        memset(st,false,sizeof st);
        for(int i=0;i<cnt;++i)
        {
            int p=primes[i];
            
            // 由于p为质数，我们将p的倍数筛掉，并且我们只能从2p和i*p较大值开始筛
            // p的倍数为合数啊，筛就完事了
            for(long long j=max((l+p-1)/p*p,2ll*p);j<=r;j+=p)
            {
                st[j-l]=true;// j-l是为了便于后面重新统计[l,r]内的素数
            }
        }

        // 由于筛除了[r,l]内的合数，所以要重新计算该范围内的质数
        cnt=0;
        for(int i=0;i<=r-l;++i)
            if(!st[i]&&i+l>1)// 1要特殊处理下，因为1不是素数也不是合数
                primes[cnt++]=i+l;// i要加上偏移量l，因为前面减了偏移量l
        
        if(cnt<2) puts("There are no adjacent primes.");
        else
        {
            int minP=0,maxP=0;
            // 使用i+1是为了防止数组里面的下标越界
            for(int i=0;i+1<cnt;++i)
            {
                int d=primes[i+1]-primes[i];
                // 更新最近距离和最远距离
                if(d<primes[minP+1]-primes[minP])minP=i;
                if(d>primes[maxP+1]-primes[maxP])maxP=i;
            }

            printf("%d,%d are closest, %d,%d are most distant.\n", primes[minP], primes[minP + 1], primes[maxP], primes[maxP + 1]);
        }
        
    }
}