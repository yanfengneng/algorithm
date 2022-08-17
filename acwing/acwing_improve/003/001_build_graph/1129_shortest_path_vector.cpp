#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
#define x first
#define y second
const int N = 2510, M = 6200*2 + 10;
int n,m,S,T;
int dist[N];            // 距离数组，记录源点到其他点的最短距离
bool v[N];              // 标记数组，标记顶点是否被访问过
vector<PII> graph[M];   // 邻接表，存储无向图
int cost[N][N];         // 邻接矩阵，存储无向图

// 生成邻接表
void bulid_adjacent_list()
{
    // 构建无向图
    for(int i=0;i<m;++i){
        int a,b,w;scanf("%d%d%d",&a,&b,&w);
        // 两条边ab ba，权值为w
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
}

// 生成邻接矩阵
void build_adjacent_array()
{
    memset(cost,0x3f,sizeof cost);
    // 构建无向图
    for(int i=0;i<m;++i){
        int a,b,w;scanf("%d%d%d",&a,&b,&w);
        // 两条边ab ba，权值为w
        cost[a][b]=cost[b][a]=w;
    }
}

// 朴素版dijkstra算法
int dijkstra(int s,int t)
{
    // 生成邻接矩阵
    build_adjacent_array();
    // 初始化源点到其他顶点的距离和顶点标记
    memset(dist,0x3f,sizeof dist),memset(v,0,sizeof v);
    // 将源点的距离初始化为0
    dist[s]=0;

    // 由于顶点是从1开始的，从1开始遍历
    // 并且由于一条边不可能经过一个顶点两次，所以最多执行n-1次
    for(int i=1;i<n;++i)
    {
        int x=-1;
        // 在未标记的点中寻找距离最小的点
        for(int j=1;j<=n;++j)
            if(!v[j]&&(x==-1||dist[j]<dist[x]))x=j;

        // 表示所有点的最短距离已经计算完了，直接退出
        if(x==-1)break;

        // 用全局最小值点x来更新其他节点
        // 由于dijkstra算法是基于贪心的，所以已经确定为最小距离的点不会被更新
        // 即此时y仅仅是未被访问过的点，然后通过x点是否能进行更新
        v[x]=true;
        for(int y=1;y<=n;++y)
            dist[y]=min(dist[y],dist[x]+cost[x][y]);
    }
    return dist[t];
} 

// 堆优化版dijksta算法
int dijkstra_heap(int s,int t)
{
    // 生成邻接表
    bulid_adjacent_list();
    // 初始化到源点的最短距离
    memset(dist,0x3f,sizeof dist);
    // 将源点的距离初始化为0
    dist[s]=0;
    // 初始化小根堆，first为最短距离，second为顶点编号
    // 利用堆的自动排序功能，最短距离会排在队头
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    // 注意堆优化版的dijstra算法是点出队列是进行打标记，因为只有只有堆顶弹出来的点才能确定最小值，因此只有在出队列的时候对点打标记
    // 开始更新s到所有点的最短距离
    while(heap.size())
    {
        // 取出堆顶元素的时间复杂度为O(1)，堆中有n个元素，时间复杂度为O(n)
        // i 为顶点编号，d 为最短距离
        auto [d,i]=heap.top();heap.pop();
        // 若顶点 i 被访问过了，则不用进行松弛了
        if(v[i])continue;
        v[i]=true;
        // 遍历 i 的所有邻接点，判断是否进行松弛。这里的总时间复杂度为O(m)
        for(auto [j,w]:graph[i]){
            // 可松弛，则更新邻接点
            if(dist[j]>dist[i]+w){
                dist[j]=dist[i]+w;
                // 堆插入元素是插在队尾，然后进行上浮操作，时间复杂度为O(logn)
                heap.push({dist[j],j});
            }
        }
    }
    return dist[t];
}

int spfa(int s,int t)
{
    // 生成邻接表
    bulid_adjacent_list();
    // 初始化距离数组和标记数组
    memset(dist,0x3f,sizeof dist),memset(v,0,sizeof v);
    // 将源点的距离初始化为0，并标记源点
    dist[s]=0,v[s]=true;
    // 将源点入队列
    queue<int> q;q.push(s);
    // 每次从队列中取出的是距离变短的点
    while(q.size()){
        int i=q.front();q.pop();
        // 顶点i出队了，标记为false
        v[i]=false;
        // 更新下i的所有出边，边 i->j 权值为 w
        // 因为源点到顶点i的最短距离变小了，那么所有以i为起点的边ij都会变小
        for(auto [j,w]:graph[i]){
            if(dist[j]>dist[i]+w){
                dist[j]=dist[i]+w;
                // 若顶点j不在队列中，则加入队列
                // 到顶点j的最短距离变小了，就加入队列。若队列中已经加入过顶点j了，就不用重复添加了。
                if(!v[j])q.push(j),v[j]=true;
            }
        }
    }
    return dist[t];
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&S,&T);
    
    cout<<dijkstra_heap(S,T)<<endl;
    return 0;
}