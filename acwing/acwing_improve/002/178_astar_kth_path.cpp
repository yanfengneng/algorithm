#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
using PIII = pair<int,PII>;
// 定义无穷大
const int INF = 0x3f3f3f3f;

const int N = 1010;
// 建立正向图邻接表、反向图邻接表
vector<PII> g[N],rg[N];
int n,m,S,T,K;
// 使用 dijkstra 算法来计算到终点的最短距离来作为评估函数
int dist[N];
// 堆优化版的dijkstra算法必须使用打标记来节点的重复访问
bool v[N];

void dijkstra()
{
    // 建立小根堆，节点值为 <到终点的距离、节点编号>
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof dist),memset(v,false,sizeof v);
    // 加入终点，初始化终点距离
    q.push({0,T});dist[T]=0;
    // 注意堆优化版的 dijstra 算法是点出队列是进行打标记，因为只有只有堆顶弹出来的点才能确定最小值，因此只有在出队列的时候对点打标记
    while(q.size())
    {
        auto [distance,i]=q.top();q.pop();
        // 若顶点 i 已被访问，则跳过
        if(v[i])continue;
        // 对顶点 i 做打标记处理
        v[i]=true;
        // 遍历顶点 i 的所有邻接点，将能更新的点进行更新
        for(auto [j,w]:rg[i])
        {
            // 到顶点 j 的距离可松弛，则进行更新
            if(dist[j]>dist[i]+w)
            {
                dist[j]=dist[i]+w;
                q.push({dist[j],j});
            }
        }
    }
}

int astar()
{
    // 终点到达不了起点，也就无解直接返回 -1
    if(dist[S]==INF)return -1;

    // <估价值距离，<真实值距离，扩展到的顶点编号 j>>
    // 估价值距离 = 起点 S 到顶点 i 的距离 + 顶点 i 到顶点 j 的距离 + 顶点 j 到终点 T 的距离
    // 真实距离 = 起点 S 到顶点 i 的距离 + 顶点 i 到顶点 j 的距离
    priority_queue<PIII,vector<PIII>,greater<PIII>> heap;
    // 开始 A* 算法从起点开始搜索
    heap.push({dist[S],{0,S}});
    // 用来记录终点被遍历的次数，第一次遍历到终点时就是第一小的距离...第k次遍历到终点时就是第k小的距离
    int cnt=0;
    while(heap.size())
    {
        // distance 表示从起点 S 到顶点 i 的真实距离
        auto t=heap.top();heap.pop();
        int i=t.y.y,distance=t.y.x;
        // 遍历到终点了，进行计数
        if(i==T)cnt++;
        // 寻找第 k 小的最短路径值了，则直接返回该最短路径值
        if(cnt==K)return distance;
        // 正向扩展所有的边：
        // 评估值距离 = 起点 S 到顶点 i 的距离 + 顶点 i 到顶点 j 的距离 + 顶点 j 到终点 T 的距离来作为标准；
        // 真实距离 = 起点 S 到顶点 i 的距离 + 顶点 i 到顶点 j 的距离
        // 扩展到的顶点编号 j
        // dist > d最优 > d[i]+f[i] 因此这样得到的肯定是最小值
        for(auto [j,w]:g[i]){
            heap.push({distance+w+dist[j],{distance+w,j}});
        }
    }
    return -1;
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