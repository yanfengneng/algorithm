#include <iostream>
using namespace std;

const int N = 1010;
int v[N],w[N];

int f[N][N];
int dp[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d%d",&v[i],&w[i]);

    // 朴素版二维dp
    /*
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
            for(int k=0;k*v[i]<=j;++k)
                // k=0表示f[i-1][j-k*v[i]]+w[i]*k=f[i-1][j]，表示我们只用考虑前i-1个物品的最大价值，不用考虑第i个物品
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
    */
    
    // 优化版二维dp
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }

    // 二维dp优化为一维dp
    for(int i=1;i<=n;++i)
        for(int j=v[i];j<=m;++j)
            // 由于j是由小到大枚举的，且j-v[i]<j，那么必定f[j-v[i]]先被计算，说明我们这里用的是第i层的j-v[i]，即f[i][j-v[i]]满足上述二维dp
            // 与01背包唯一的区别在于j的枚举方向不一样，01背包是j由大到小枚举的，而完全背包是j由小到大枚举的
            // 因为01背包的j要是从小到大枚举的，那么我们用的是f[i][j-v[i]]，而不是f[i-1][j-v[i]]，只由大到小枚举，才能保证使用f[i-1][j-v[i]]
            // 因为这样可保证f[j-v[i]]没有被计算过，所以01背包要从大到小枚举
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    
    printf("%d\n",dp[m]);
    return 0;
}