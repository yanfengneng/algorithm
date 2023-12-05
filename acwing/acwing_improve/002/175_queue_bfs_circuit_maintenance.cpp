#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using PII = pair<int,int>;

const int N = 510;
// 最短距离数组
int dist[N][N];
// 由于本题存在边权为0的边，使用双端队列时会出现重复访问点，因此需要使用一个标记数组
bool vis[N][N];
// 输入数据
int n,m;
char g[N][N];

// '/' 需要转义，按[左上、右上、右下、左下]的顺序进行四个方向的枚举
char cs[]="\\/\\/";
// 方向数组
int dx[]={-1,-1,1,1},dy[]={-1,1,1,-1};
// 需要踩过的格子方向
int ix[]={-1,-1,0,0},iy[]={-1,0,0,-1};

int bfs()
{
    // 初始化距离数组和标记点数组
    memset(dist,0x3f,sizeof dist),memset(vis,false,sizeof vis);
    // 初始化起点的距离，以及将起点加入双端队列
    dist[0][0]=0;
    deque<PII> q;
    q.push_back({0,0});
    // 开始进行 bfs
    while(q.size())
    {
        // 获得队头坐标，并将队头出队
        auto [x,y]=q.front();q.pop_front();
        // 与堆优化的dijkstar算法一样，必须在出队的时候才知道每个点的最终最短距离，而一般的bfs才进队列的时候就知道最短距离了。
        if(x==n&&y==m)return dist[x][y];
        if(vis[x][y])continue;
        // 这里使用的是出队列时对坐标点进行打标记，因为一个点可能被访问多次，因此出队列打标记来防止点被访问多次。
        vis[x][y]=true;
        // 进行四个方向的枚举
        for(int i=0;i<4;++i)
        {
            // 格子边角上点的坐标
            int nx=x+dx[i],ny=y+dy[i];
            // 扩展点越界了，则跳过该方向的扩展
            if(nx<0||ny<0||nx>n||ny>m)continue;
            // 踩到格子的坐标
            int gx=x+ix[i],gy=y+iy[i];
            // 不需要旋转，边权为0；需要旋转，边权为1；
            int w=g[gx][gy]==cs[i]?0:1;
            // 从点(x,y)到(nx,ny)的距离
            int d=dist[x][y]+w;
            // 更新到达点(nx,ny)的最短距离
            if(d<dist[nx][ny])
            {
                dist[nx][ny]=d;
                // 扩展出来的点边权为1，则添加到队尾；扩展出来的点边权为0，添加到队头。
                if(w)q.push_back({nx,ny});
                else q.push_front({nx,ny});
            }
        }
    }
    return -1;
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)scanf("%s",g[i]);

        // 由于起点为(0,0)是偶数点，斜着走的话，横纵坐标同时变化1个单位，因此最终也只能走到偶数点。若终点为奇数点的话，直接输出不可能即可。否则进行bfs算最短距离。
        // 双端队列主要用于解决图中边权值只有 0 和 1 的最短路问题
        if(n+m&1)puts("NO SOLUTION");
        else printf("%d\n",bfs());
    }

    return 0;
}