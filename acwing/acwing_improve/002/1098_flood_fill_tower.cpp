#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int g[N][N];
// 标记数组：表示该点是否被访问过
bool v[N][N];
using PII = pair<int,int>;
// 方向数组：左上右下
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};

int n,m;

// 进行宽搜灌溉
int bfs(int i,int j)
{
    queue<PII> q;
    q.push({i,j});
    // 历史和现实告诉我们进队列就要打标记
    v[i][j]=1;
    int area=0;
    while(q.size())
    {
        // 出队列时统计房间面积
        auto [x,y]=q.front();q.pop();
        area++;
        for(int k=0;k<4;++k)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m||v[nx][ny])continue;
            // 点(x,y)的k方向上为墙，就不能进行统计了
            if(g[x][y]>>k&1)continue;
            // 进队列，并打上标记
            q.push({nx,ny});
            v[nx][ny]=1;
        }
    }
    return area;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&g[i][j]);
    
    int cnt=0,area=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!v[i][j])
            {
                cnt++;
                area=max(area,bfs(i,j));
            }
    printf("%d\n%d\n",cnt,area);
    return 0;
}