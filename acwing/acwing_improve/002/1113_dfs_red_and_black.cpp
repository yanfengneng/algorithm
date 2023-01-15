#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m;
const int N = 30;
char g[N][N];
// 标记数组，防止点被重复访问造成死循环
bool v[N][N];

int dfs(int x,int y)
{
    int cnt=1;
    v[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m || v[nx][ny] || g[nx][ny]=='#')continue;
        cnt+=dfs(nx,ny);
    }
    return cnt;
}

int main()
{
    while(scanf("%d%d",&m,&n), n || m)
    {
        for(int i=0;i<n;++i)scanf("%s",g[i]);
        int x,y;
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)
            if(g[i][j]=='@')x=i,y=j;
        memset(v,0,sizeof v);
        printf("%d\n",dfs(x,y));
    }
    return 0;
}