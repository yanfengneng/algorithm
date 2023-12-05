#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// 线性筛法求欧拉函数
const int N = 1e6+10;
int primes[N],cnt=0;
bool st[N];// 标记是和数还是质数，0为质数，1为合数
int phi[N];

LL get_eulers(int n)
{
    // 根据定义Ψ(1)=1
    phi[1]=1;
    // 开始利用线性筛法求欧拉函数
    for(int i=2;i<=n;++i)
    {
        // i为质数则存储在质数数组primes中
        if(!st[i])
        {
            primes[cnt++]=i;
            // 这里是根据欧拉函数本身的定义出发得到的，即1~N中与N互质的数的个数称为欧拉函数
            // 显然一个质数p有p-1个数与其互质，也就是1~(1-p)都是和p是互质的
            phi[i]=i-1;
        }
        // 给当前数i乘上一个质因子pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            // 对于任一个合数x，若pj是x的最小质因子，当i<x/pj时，一定会被筛掉
            st[i*primes[j]]=1;
            // 当i%primes[j]==0时，利用最小质因子进行筛选
            if(i%primes[j]==0)
            {
                /*
                这里是利用欧拉函数的算术定理推出的公式：
                    phi(i*pj)=i*pj*(1-p1)*...*(1-pk)=pj*phi(i)
                    i*pj比i多乘了一项pj，那么pj*i分解之后的所有质因数，只是比i多了一个pj而已，并且pj是i的一个质因子，所以i*pj的所有质因子都在i中出现过了，所以前面总数多了一个pj，乘上即可
                */
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }
            // 当i%primes[j]!=0时，那么pj一定是i*pj的最小质因子，而且pj没有被包含在i的质因子当中，所以phi(i*pj)=i*pj*(1-1/p1)*...*(1-1/pk)*(1-1/pj)=pj*(1-1/pj)*phi(i)=(pj-1)*phi(i)
            phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }

    LL res=0;
    for(int i=1;i<=n;++i)res+=phi[i];
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",get_eulers(n));
    return 0;
}
