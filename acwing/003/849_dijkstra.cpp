#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int N = 510;
// 由于本题为稠密图，所以用邻接矩阵存放效果好
// cost用来存放邻接矩阵，dist用来存放最短距离
int cost[N][N],dist[N];
// visited用来标记点是否使用
bool visited[N];

// 计算从源点s出发到其他所有点的最短距离
int dijkstra(int s)
{
    // 初始化距离和顶点标记
    memset(dist,0x3f,sizeof dist);
    memset(visited,0,sizeof visited);
    dist[s]=0;

    // 由于顶点是从1开始的，从1开始遍历
    // 并且由于一条边不可能经过一个顶点两次，所以最多执行n-1次
    for(int i=1;i<n;++i)
    {
        int x=-1;
        // 在未标记的点中寻找距离最小的点
        for(int j=1;j<=n;++j)
            if(!visited[j]&&(x==-1||dist[j]<dist[x]))x=j;

        // 表示所有点的最短距离已经计算完了，直接退出
        if(x==-1)break;

        // 用全局最小值点x来更新其他节点
        // 由于dijkstra算法是基于贪心的，所以已经确定为最小距离的点不会被更新
        // 即此时y仅仅是未被访问过的点，然后通过x点是否能进行更新
        visited[x]=true;
        for(int y=1;y<=n;++y)
            dist[y]=min(dist[y],dist[x]+cost[x][y]);
    }

    // 不存在最短距离就返回-1；否则返回最短距离
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    // 初始化邻接矩阵
    memset(cost,0x3f,sizeof cost);
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        // 由于存在自环和重边，我们仅需保留最短的权值就行了
        cost[x][y]=min(cost[x][y],z);
    }

    printf("%d\n",dijkstra(1));
    return 0;
}