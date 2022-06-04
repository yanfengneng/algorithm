#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char g[N][N];
int dist[N][N];
using PII = pair<int ,int>;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;

void bfs()
{
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='1')dist[i][j]=0,q.push({i,j});
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||dist[nx][ny]!=-1)continue;
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",g[i]);

    bfs();
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)printf("%d ",dist[i][j]);
        puts("");
    }
    return 0;
}