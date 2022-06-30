#include <iostream>
using namespace std;

const int N = 1e6+10;
// primes储存的是所有质数，cnt表示质数数量  
int primes[N],cnt=0;
// 标记是合数还是质数，0为质数，1为合数
bool flag[N];

// 线性质数筛法，让每个合数只会被它的最小质因子筛一次
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // i为质数，则存在primes中
        if(!flag[i])primes[cnt++]=i;

        // 给当前数i乘上一个质因子pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            // 对于任一个合数x，若pj是x的最小质因子，当i<x/pj时，一定会被筛掉
            flag[i*primes[j]]=1;
            /*
                i%pj==0，表示pj一定是i的最小质因子，因为我们是由小到大枚举质因子的，那么pj一定是pj*i的最小质因子，之后的pj+1,pj+2...之类的
                质因子就不是p[j+x] *i 的最小质因子了了，因为p[j+x] *i 的最小质因子为i的最小质因子pj，由于我们是按最小质因子进行筛选的，所以
                p[j+x] *i 之前肯定被被它的最小质因子pj已经筛了，我们继续筛的话，必定会重复的。

                i%pj!=0，表示pj比i的所有质因子都要小，因为i的质因子是必定可以整除i的，而i%pj!=0，表示pj比i的所有质因子都要小，这样我们筛
                i*pj是用最小质因子pj筛的，然后我们在枚举pj+1,pj+2，来给i乘上下一个最小质因子，所以不用break；

                总结一句话：线性筛只利用最小质因子进行筛选
            */
            if(i%primes[j]==0)break;
        }
    }
}

// 欧拉筛选
bool v[N];
void oula_primes(int n)
{
    memset(v,0,sizeof v);
    int m=0;
    for(int i=2;i<=n;++i)
    {
        if(v[i])continue;
        m++;
        for(int j=2*i;j<=n;j+=i)v[j]=1;
    }
    cout<<m<<endl;
}

int main()
{
    int n;
    scanf("%d",&n);
    get_primes(n);
    printf("%d\n",cnt);
    return 0;
}