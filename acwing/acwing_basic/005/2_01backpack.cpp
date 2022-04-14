#include <iostream>
using namespace std;

const int N = 1010;

int n,m;
int V[N],W[N];
int f1[N][N];
int f2[N];

// 二维dp
void dp1()
{
    // 开始进行dp
    // 初始化时：f[0][j]=0表示前0个物品选出总体积不超过j的价值为0；所以i从1开始循环
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            f1[i][j]=f1[i-1][j];
            // 由于右边子集不一定存在，因为右边集合必须包含第i个物品，所以只有当前的体积j大于等于v[i]时，才能选第i号物品
            if(j>=V[i])f1[i][j]=max(f1[i][j],f1[i-1][j-V[i]]+W[i]);
        }
    cout<<f1[n][m]<<endl;
}


// 优化后的一维dp
void dp2()
{
    for(int i=1;i<=n;++i)
        // 从大到小进行枚举，保证f[j-v[i]]还没有被更新过，此时的f[j-v[i]]是上一层的f[i-1][j-v[i]]
        for(int j=m;j>=V[i];--j)
            f2[j]=max(f2[j],W[i]+f2[j-V[i]]);
    
    cout<<f2[m]<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>V[i]>>W[i];
    
    dp2();
    
    return 0;
}