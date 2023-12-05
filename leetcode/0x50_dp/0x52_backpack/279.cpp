#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10, M = 110;
// 存放每种物品的体积
int v[M];
// 状态f[i][j]表示从前i件物品中选，且总体积等于j的方案集合所有物品的最小数量
int f[M][N];
int f1[N];

class Solution {
public:
    // 转换为完全背包做：有m种物品，每种物品的体积分别是1,4,9...sqrt(n)，每种物品可以选无限个，求能刚好装满体积n的最小物品数量
    int numSquares(int n) {
        return dp2(n);
    }

    // 二维dp
    int dp1(int n)
    {
        // 预处理每种物品的体积，下标从1开始存储物体的体积
        int m=0;
        for(int i=1;i<=n/i;i++)v[++m]=i*i;
        // 初试所有状态为无效值
        memset(f,0x3f,sizeof f);
        // 初试状态：选取0个物品且总体积为0的最小物品数量为0
        f[0][0]=0;
        // 开始进行状态转移，这里是组合(每种物品选与不选)，物品在外层循环，体积(背包)在内层循环
        for(int i=1;i<=m;++i)
            for(int j=0;j<=n;++j)
            {
                // 不选物品i且总体积刚好为j的最少物品数
                f[i][j]=f[i-1][j];
                // f[i][j-v[i]]=min(f[i-1][j-k*v[i]])，其中k大于等于1；所以只用f[i][j-v[i]]+1就可以推出f[i][j]的所有右子集
                if(j>=v[i])f[i][j]=min(f[i][j],f[i][j-v[i]]+1);
            }
        // 最终结果为从前m种物品中选，且总体积刚好n的最少物品数
        return f[m][n];
    }

    // 优化为一维dp
    int dp2(int n)
    {
        memset(f1,0x3f,sizeof f1);
        // 初试状态：选取0个物品且总体积为0的最小物品数量为0
        f1[0]=0;
        // 背包问题是组合问题，外层循环枚举物品，内层循环枚举体积
        for(int i=1;i<=n/i;++i)
        {
            int v=i*i;// 物品i的体积为v
            for(int j=v;j<=n;++j)
                 // j-v[i]<=j，所以由小到大枚举j时，较小值j-v[i]已经被先计算出来了，此时的f[j-v[i]]就是第i层的f[i][j-v[i]]
                f1[j]=min(f1[j],f1[j-v]+1);
        }
        return f1[n];
    }
};

int main()
{
    cout<<Solution().numSquares(13)<<endl;
    return 0;
}