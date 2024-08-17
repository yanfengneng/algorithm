#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 1010;
using PII = pair<int,int>;
int g[N][N];
// 数组元素为一个pair对象，pre存的是当前点下一个点的坐标
PII pre[N][N];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n;

void bfs(int sx,int sy)
{
    queue<PII> q;
    q.push({sx,sy});
    // 入队就要打标记
    memset(pre,-1,sizeof pre);
    // 这里只要弄一个不是-1的数都行
    pre[sx][sy]={0,0};
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // 越界或者遇到墙了或者先前点已经被访问过了，不需要访问该点了
            if(nx<0||ny<0||nx>=n||ny>=n||g[nx][ny]||pre[nx][ny].x!=-1)continue;
            // 入队并进行打标记
            q.push({nx,ny});
            // 当前点的下一个点为(x,y)
            pre[nx][ny]={x,y};
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&g[i][j]);
    
    // 从终点反推到起点的路径
    bfs(n-1,n-1);
   
    PII end={0,0};
    while(1)
    {
        printf("%d %d\n",end.x,end.y);
        if(end.x==n-1&&end.y==n-1)break;
        end=pre[end.x][end.y];
    }

    return 0;
}