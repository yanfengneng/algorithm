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
                i%pj==0，表示pj一定是i的最小质因子，因为我们是由小到大枚举质因子的，那么pj一定是pj*i的最小质因子
                i%pj!=0，表示pj比i的所有质因子都要小，那么pj*i的最小质因子也就是pj了
                至于为什么要break，因为在枚举下去的话，pj*i的质因子pj不是最小质因子了，而线性筛法就是利用最小质因子进行筛选的
            */
            if(i%primes[j]==0)break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    get_primes(n);
    printf("%d\n",cnt);
    return 0;
}