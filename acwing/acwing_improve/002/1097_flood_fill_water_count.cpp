#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
#define x first
#define y second
const int N = 1010;
bool v[N][N];
char g[N][N];
// 方向数组
int dx[]={1,0,-1,0,1,-1,1,-1},dy[]={0,1,0,-1,1,-1,-1,1};
int n,m;

// dfs来进行灌溉
void dfs(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||g[i][j]=='.'||v[i][j])return;
    v[i][j]=1;
    for(int k=0;k<8;++k)
        dfs(i+dx[k],j+dy[k]);
}

// bfs来进行灌溉
void bfs(int i,int j)
{
    queue<PII> q;
    // 历史和进程告诉我们入队就要打标记
    q.push({i,j});
    v[i][j]=1;
    while(q.size())
    {
        auto [sx,sy]=q.front();q.pop();
        for(int k=0;k<8;++k)
        {
            int nx=sx+dx[k],ny=sy+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m||g[nx][ny]=='.'||v[nx][ny])continue;
            // 历史和进程告诉我们入队就要打标记
            v[nx][ny]=1;
            q.push({nx,ny});
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",g[i]);

    int res=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='W'&&!v[i][j])
            {
                bfs(i,j);
                res++;
            }

    printf("%d\n",res);
    return 0;
}