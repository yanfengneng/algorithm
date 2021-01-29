#include <iostream>
using namespace std;

const int N = 1010;
int v[N],w[N];
int f[N][N];
// dp表示优化为一维数组
int dp[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];

    // 由于f[0][0~m]为0件物品的能产生的最大价值为0，全局变量初始化为0了，就不用管了
    // 所以i从1开始循环
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            // 右边情况：不含i并且总体积不超过j的最大价值。即左边情况是一定存在的
            // 而右边情况不一定存在，可能为空集，即当j<vi时，也就是装不下vi时，为空集
            // 先左后右，即先执行左边情况，再执行右边情况
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    
    // 二维dp降维成一维dp
    for(int i=1;i<=n;++i)
        for(int j=m;j>=v[i];--j)
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);

    cout<<dp[m]<<endl;
    return 0;
}