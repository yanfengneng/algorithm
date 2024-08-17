#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 10;
// 标记数组，防止点被重复访问
bool v[N][N];
// 方向数组：8个方向
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

int res;
// 其中cnt表示正在搜索第cnt个点，总共有n*m个点
void dfs(int x,int y,int cnt)
{
    if(cnt==n*m)// 表示找到一种搜索方案，对该方案进行计数
    {
        res++;
        return;
    }
    // 标记该点已经被访问了
    v[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        // 越界点和已经被访问过的点进行跳过
        if(nx<0 || nx>=n || ny<0 || ny>=m || v[nx][ny])continue;
        // 下次访问第cnt+1个点
        dfs(nx,ny,cnt+1);
    }
    // 恢复现场，便于进行下一条分支
    v[x][y]=0;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        res=0;
        int x,y;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        dfs(x,y,1);
        printf("%d\n",res);
    }
    return 0;
}