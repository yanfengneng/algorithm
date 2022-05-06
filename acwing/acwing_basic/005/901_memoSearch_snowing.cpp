#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int h[N][N];
// 状态f[i][j]=c表示从(i,j)开始滑的路径值，也就是我们平时写的记忆化数组
int f[N][N];
// 方向数组
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;

// 用递归的方式实现状态转移，也就是动态规划的自顶向下解法--记忆化搜索
int dp(int x,int y)
{
    // 该状态已被计算，直接返回
    if(f[x][y]!=-1)return f[x][y];
    // 从(x,y)开始进行状态转移，起点(x,y)的路径值为1
    f[x][y]=1;
    // 开始四个方向的状态转移
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        // 转移到的点需要没越界，而且转移点的高度要小于当前点的高度，才能进行转移，使用dp()来得到(nx,ny)的路径值
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&h[nx][ny]<h[x][y])
            f[x][y]=max(f[x][y],dp(nx,ny)+1);
    }
    // 返回最终转移得到的最大路径值
    return f[x][y];
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>h[i][j];
    // 初始化状态数组，来表示每个点都没有被算过
    memset(f,-1,sizeof f);
    int res=0;
    // 枚举从每个点出发的最大路径值，只能用dp(i,j)的返回值，是求出这个状态的最路径值，不能直接调用f[i][j]，因为f[i][j]还没有被求出来
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            res=max(res,dp(i,j));
    cout<<res<<endl;
    return 0;
}