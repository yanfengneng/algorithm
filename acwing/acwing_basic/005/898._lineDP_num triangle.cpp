#include <bits/stdc++.h>
using namespace std;

const int N = 510,INF = 1e9;
int a[N][N],f1[N][N],f2[N][N];
int n;

// 自顶向下进行dp
void dp1()
{
    // 这里的i要从1开始初始化，因为计算第二行数据时，会用到第一行的中的f[1][0]，f[1][2]，显然j的初始化要从[0,i+1]了，因为上一行中的第0列和第i列的状态都要被用到，所以初始化为负无穷
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i+1;++j)
            f1[i][j]=-INF;
    f1[1][1]=a[1][1];

    // 开始进行状态转移
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
            f1[i][j]=max(f1[i-1][j-1],f1[i-1][j])+a[i][j];

    // 在最后一行中寻找路径最大值
    int res=-INF;
    for(int i=1;i<=n;++i)res=max(res,f1[n][i]);
    cout<<res<<endl;
}

int main()
{
    cin>>n;
    // 在使用自顶向下进行dp时，需要使用f[i-1]这种状态，所以下标从1开始读入
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cin>>a[i][j];
    dp1();
    return 0;
}