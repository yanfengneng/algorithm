#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
using PIII = pair<int,PII>;

const int N = 1010;
// 建立正向图邻接表、反向图邻接表
vector<int> g[N],rg[N];
int n,m,S,T,K;
// 使用 dijkstra 算法来计算到终点的最短距离来作为评估函数
int dist[N][N];
// 堆优化版的dijkstra算法必须使用打标记来节点的重复访问
bool v[N];

void dijkstra()
{
    // 建立小根堆，节点值为<到终点的距离、节点编号>
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist),memset(v,false,sizeof v);
    // 加入终点，初始化终点距离
    q.push({0,T}),dist[T]=0;
    // 注意堆优化版的dijstra算法是点出队列是进行打标记，因为只有只有堆顶弹出来的点才能确定最小值，因此只有在出队列的时候对点打标记
    while(q.size())
    {

    }
}

int astar()
{

}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b,l;scanf("%d%d%d",&a,&b,&l);
        // 建立正向图邻接表、反向图邻接表
        g[a].push_back({b,l}),rg[b].push_back({a,l});
    }
    scanf("%d%d%d",&S,&T,&K);
    // 起点与终点相同时，则dist[S→S]=0这种情况就要舍去，因为题目要求最短路中至少要包含一条边，因此需要排除dist[S→S]=0这种情况，使第k小变成第k+1小
    if(S==T)K++;
    // 使用 dijkstra 算法来计算每个点到终点的最短距离来作为评估函数
    dijkstra();

    printf("%d\n",astar());
    return 0;
}