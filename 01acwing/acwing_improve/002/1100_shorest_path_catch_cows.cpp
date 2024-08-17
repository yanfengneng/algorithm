#include <bits/stdc++.h>
using namespace std;

// 距离不用开两倍，只用先减再乘2就好了
const int N = 1e5+10;
int dist[N];
int n,k;

int bfs()
{
    // 初始化距离数组已经队列，并将起点加入队列和距离数组中
    memset(dist,-1,sizeof dist);
    queue<int> q;
    q.push(n);
    dist[n]=0;
    // 队列中的点到起点的距离一定是递增的，因为我们是一层一层的进行扩展的，所以第一个找到终点的距离一定是最短距离
    while(q.size())
    {
        int t=q.front();q.pop();
        // 走到终点了
        if(t==k)return dist[k];
        // 把所有边权为1且未访问过的顶点加入队列中，并更新最短距离
        if(t+1<N&&dist[t+1]==-1){
            dist[t+1]=dist[t]+1;
            q.push(t+1);
        }
        if(t-1>=0&&dist[t-1]==-1){
            dist[t-1]=dist[t]+1;
            q.push(t-1);
        }
        if(t*2<N&&dist[t*2]==-1){
            dist[t*2]=dist[t]+1;
            q.push(t*2);
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&k);
    printf("%d\n",bfs());
    return 0;
}