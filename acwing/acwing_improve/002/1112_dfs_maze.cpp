#include <bits/stdc++.h>
using namespace std;

// 方向数组
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
const int N = 110;
char g[N][N];
int n;
bool v[N][N]; // 标记数组，标记某个点是否被访问过了
int xa,ya,xb,yb;

int dfs(int x,int y)
{
    if(g[x][y]=='#')return false;
    if(x==xb and y==yb)return true;

    v[x][y]=true;// 标记该点已经被访问，防止重复访问
    // 开始向四个方向进行扩展
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n || v[nx][ny])continue;
        if(dfs(nx,ny))return true;
    }
    return false;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        memset(v,false,sizeof v);
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%s",g[i]);
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        if(dfs(xa,ya))puts("YES");
        else puts("NO");
    }
    return 0;
}