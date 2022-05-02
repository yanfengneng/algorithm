#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9+7;
int n;
// f1[i][j]表示从数字[1~i]中选，总体积恰好为j的方案数
int f1[N][N],f2[N];

// 朴素版完全背包解法
void complete_backpack_1()
{
    // 求最大价值时，当体积为0时，价值显然为0；求数量时，当体积为0时，这显然是一种方案，因此f1[i][0]初始化为1
    for(int i=0;i<=n;++i)f1[i][0]=1;

    // 开始进行状态转移
    for(int i=1;i<=n;++i)
        for(int j=0;j<=n;++j)
        {
            // 第i个物品选0个
            f1[i][j]=f1[i-1][j]%mod; 
            // f[i][j-i]=max(f[i-1][j-k*i])，其中k>=1；所以只用f[i][j-i]就可以推出f[i][j]的所有右子集了
            if(j>=i)f1[i][j]=(f1[i][j]+f1[i][j-i])%mod;
        }
    cout<<f1[n][n]<<endl;
}

// 空间优化版完全背包解法
void complete_backpack_2()
{
    // 初始化：f2[0]=1表示所有数都不选时，总和为0的方案数有1个；f2[1~n]=0表示一个数都不选时，总体积为1~n的方案数有0个
    f2[0]=1;
    // 由于i是从小到大进行枚举的，所以状态转移用到的f2[j]是没有更新过的，即是第i-1层的f2[i-1][j]
    // 由于j是从小到大进行枚举的，所以状态转移中的f2[j-i]是当前第i层被更新过的，即是第i层的f2[i][j-i]；j-i<=j 较小的j-i先被计算了，是第i层的f2[i][j-i]
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            f2[j]=(f2[j]+f2[j-i])%mod;
    cout<<f2[n]<<endl;
}

// f[i][j]表示总和是i，并且恰好表示成j个数的方案数
int f3[N][N];
// 计数类dp解法
void count_dp()
{
    // f[0][0]=1表示总和为0，并且由0个数表示的方案数为1个；f[0][1~n]=0表示总和为0，并且由1~n个数表示的方案数为0个
    f3[0][0]=1;
    // 从总和为1开始进行状态转移
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            // 将由j个数构成总和为i的方案数，划分为两个方案数：一个方案数是j个数中最小值等于1；另一个方案数是j个数的最小值都大于1，即j个数都大于1
            // 第一个方案数则可以将方案中的那个最小值1减去，这样就剩下j-1个数构成总和i-1的方案数了，这俩是等价的
            // 第二个方案数则可以将方案中的j个数都减去1，这样总和会剩下i-j了，这样j个数构成总和为i-j的方案数是等价的
            f3[i][j]=(f3[i-1][j-1]+f3[i-j][j])%mod;
    // 求解所有总和为n的方案数
    int res=0;
    for(int i=1;i<=n;++i)res=(res+f3[n][i])%mod;
    cout<<res<<endl;
}   

int main()
{
    scanf("%d",&n);
    // complete_backpack_2();
    count_dp();
    return 0;
}