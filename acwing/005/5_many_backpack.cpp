#include <iostream>
#include <algorithm>
using namespace std;

const int N = 12010,V = 2010;

int n,m;
int v[N],w[N];
int f[V];

// 二进制优化版多重背包
int main()
{
    scanf("%d%d",&n,&m);

    // 用cnt存储新的物品体积和价值的编号
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        int a,b,s;
        scanf("%d%d%d",&a,&b,&s);
        int k=1;
        // 只要k<=s，都可以把s分组
        while(k<=s)
        {
            cnt++;// 现罢新的物品编号+1

            // k个物品一组，每组里面物品的体积和价值都扩大k倍
            v[cnt]=a*k;
            w[cnt]=b*k;

            // 然后将总组数减掉k，再将k扩大两倍，下一组的大小为2*k
            s-=k;
            k*=2;
        }
        // 最后s还大于0，我们还剩余一组，需要补上
        // 最后一组就是余数c呀，这个还要算上的
        if(s>0)   
        {
            cnt++;
            v[cnt]=a*s,w[cnt]=b*s;
        }
    }

    // n 为新的物品个数
    n=cnt;
    for(int i=1;i<=n;++i)
        for(int j=m;j>=v[i];--j)
            // 由于j是由大到小枚举的，所以这里的f[j-v]没有被计算过，是第i-1层的f[j-v]
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    printf("%d\n",f[m]);
    return 0;
}