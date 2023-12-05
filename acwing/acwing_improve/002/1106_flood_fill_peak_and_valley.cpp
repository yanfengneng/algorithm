#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 1010;
int h[N][N];
// 标记数组
bool v[N][N];
// 方向数组
int dx[]={1,0,-1,0,1,-1,1,-1},dy[]={0,1,0,-1,1,-1,-1,1};

int n;

void bfs(int i,int j,bool& f1,bool& f2)
{
    queue<PII> q;
    // 历史和现实告诉我们入队就要打标记
    q.push({i,j});
    v[i][j]=1;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<8;++k)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=n)continue;
            // 找到山脉的边界了
            if(h[x][y]!=h[nx][ny])
            {
                if(h[nx][ny]>h[x][y])f1=true;
                else f2=true;
            }
            // 同属一个连通块，且没有被重复访问过
            else if(!v[nx][ny])
            {
                q.push({nx,ny});
                v[nx][ny]=1;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&h[i][j]);

    int peak=0,valley=0;       
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(!v[i][j])
            {
                // f1表示是否有比这个连通块更大的点，f2表示是否有比这个连通块更小的点
                bool f1=false,f2=false;
                bfs(i,j,f1,f2);
                // 无更大的点，为山峰
                if(!f1)peak++;
                // 无更小的点，为山谷
                if(!f2)valley++;
            }
    printf("%d %d\n",peak,valley);
    return 0;
}