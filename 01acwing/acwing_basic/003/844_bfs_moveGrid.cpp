#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

using PII=pair<int,int>;
const int N = 110;

int n,m;
int grid[N][N],dist[N][N];

// 队列；pre用来记录路径
PII q[N*N],pre[N][N];

// 4个方向数组
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int bfs()
{
    // 初始化队列，并把(0,0)加入队列中
    // 在这里把队尾tt初始化为0是因为加入{0,0}后，tt由-1变成0了
    int hh=0,tt=0;
    q[0]={0,0};
    
    // 初始化距离
    memset(dist,-1,sizeof dist);
    dist[0][0]=0;

    // 队列不为空
    while(hh<=tt)
    {
        // 队头出队列
        auto t=q[hh++];

        // 将t周围的四个点的距离更新
        for(int i=0;i<4;++i)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            // (x,y)没有越界且可以可以走通，并且dist[x][y]没有被走过
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==0&&dist[x][y]==-1)
            {   
                // 更新距离，并加入队列
                dist[x][y]=dist[t.first][t.second]+1;
                // (x,y)的前一个点为t，即t->(x,y)
                pre[x][y]=t;
                q[++tt]={x,y};
            }
        }
    }

    int x=n-1,y=m-1;
    // 由于BFS遍历是权值为1的图，所以从起点到终点的距离其实为最短路，等价于BFS遍历的层数
    // prev数组是根据层数来记录前一个点的坐标的，因此从终点到起点的层数所经历的点即为最短路，终点也只能从最短路回去
    while(x||y)
    {
        cout<<x<<" "<<y<<endl;
        auto t=pre[x][y];
        x=t.first,y=t.second;
    }
    return dist[n-1][m-1];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&grid[i][j]);
    printf("%d\n",bfs());
    return 0;
}