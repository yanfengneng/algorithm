#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 155;
char g[N][N];
int dist[N][N];// 表示起点到(i,j)的距离
int dx[]={-1,-2,-2,-1,1,2,2,1},dy[]={-2,-1,1,2,2,1,-1,-2};// 表示方向数组
int n,m;

int bfs()
{
    int sx,sy;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='K')
            {
                sx=i,sy=j;
                break;
            }
    // 开始进行bfs
    // 初始化距离数组为-1
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    // 初始化起点
    q.push({sx,sy});
    dist[sx][sy]=0;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<8;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // 越界或者遇到障碍或者遇到已访问过的点
            if(nx<0||ny<0||nx>=n||ny>=m||g[nx][ny]=='*'||dist[nx][ny]!=-1)continue;
            // 找到终点了
            if(g[nx][ny]=='H')return dist[x][y]+1;
            // 加入队列
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)scanf("%s",g[i]);
    printf("%d\n",bfs());
    return 0;
}