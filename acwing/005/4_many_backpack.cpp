#include <iostream>
using namespace std;

const int N = 110;
int v[N],w[N],s[N];
int f[N][N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    
    // 朴素版多重背包
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=s[i]&&k*v[i]<=j;++k) 
                // k=0时为f[i-1][j]表示我们只用考虑前i-1个物品的价值的最大值
                // k!=0时表示我们考虑前i个物品，但是不包含第i号物品，最后再加上k个第i个物品的最大值
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
    
    printf("%d\n",f[n][m]);
    return 0;
}