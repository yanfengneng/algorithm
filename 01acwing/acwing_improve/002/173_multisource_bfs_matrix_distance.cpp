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
    // 由于多源 BFS 从入队开始就是最小值了，也就是一旦入队之后它的距离是不会被更新的，也就是距离只会被更新一次，所以不需要初始化为0x3f，只需初始化一个特殊值-1即可
    memset(dist,-1,sizeof dist);
    queue<PII> q;
    // 队列中的所有元素都是单调递增的，而且所有边的权重都一样都是1，因此后面点的距离是一定大于队头点的距离的，所以一旦一个元素被队头更新了，就一定不会被后面的任何一个元素进行更新了，也就是只会被更新一次
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='1')dist[i][j]=0,q.push({i,j});
    
    // 以下部分和单源BFS一样的
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            // 越界或者距离已经被计算出来了，则不用访问这个点了
            if(nx<0||ny<0||nx>=n||ny>=m||dist[nx][ny]!=-1)continue;
            // 更新距离，并加入队列
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
    // 输出所有距离
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)printf("%d ",dist[i][j]);
        puts("");
    }
    return 0;
}