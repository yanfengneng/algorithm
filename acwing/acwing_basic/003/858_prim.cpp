#include <iostream>
#include <cstring>
using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
// grid：因为是稠密图，所以要用临界矩阵来存储图；dist表示剩余节点到最小生成树集合的最短距离
int grid[N][N],dist[N];
// 记录顶点i是否在生成树中
bool flag[N];

int n,m;

int prim()
{
    // 初始化距离数组和标记数组
    memset(dist,0x3f,sizeof dist);
    memset(flag,0,sizeof flag);

    int res=0;

    // 遍历n次，来寻找最短距离
    for(int i=0;i<n;++i)
    {
        int t=-1;
        // 寻找集合外的点--到集合的最短距离
        for(int j=1;j<=n;++j)
            // t=-1表示当前还没有找到任何一个点
            if(!flag[j]&&(t==-1||dist[j]<dist[t]))
                t=j;
        
        // i 不是第一个点，dist[t]为INF表明到最小生成树的距离不存在，即图是不连通的
        if(i&&dist[t]==INF)return INF;
         
        // 第一个点到集合的距离为0，其他点到集合的最短距离为dist[t]，并把t加入最小生成树
        if(i)res+=dist[t];
        flag[t]=true;

        // 更新到最小生成树的最小距离，t->j为连边
        for(int j=1;j<=n;++j)dist[j]=min(dist[j],grid[t][j]);
    }

    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    // 先初始化邻接矩阵
    memset(grid,0x3f,sizeof grid);

    // 自环初始化为0
    for(int i=1;i<=n;++i)grid[i][i]=0;

    while(m--)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        // 由于为无向图，需要建立两条边，并且由于存在重边，所以要保留较小的边
        grid[x][y]=grid[y][x]=min(grid[x][y],w);
    }

    int t=prim();
    if(t==INF)puts("impossible");
    else printf("%d\n",t);

    return 0;
}