#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

using PII = pair<int,int>;
const int N = 1e6+10;

// 邻接表，h为表头数组，w为权值，e为存放顶点的编号，ne为next数组，idx为当前可用的节点编号
int h[N],w[N],e[N],ne[N],idx=0;
int dist[N];
bool flag[N];
int n,m;

// 插入边ab且边的权值为c 
void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

// 总时间复杂度为O(mlogn)
int dijkstra(int s)
{
    // 初始化距离
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;

    // 初始化小根堆，first为最短距离，second为顶点编号
    // 利用堆的自动排序功能，最短距离会排在队头
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});

    // 开始更新s到所有点的最短距离
    while(!heap.empty())
    {
        // 取出堆顶元素的时间复杂度为O(1)，堆中有n个元素，时间复杂度为O(n)
        auto t=heap.top();
        heap.pop();

        // v 为顶点编号； distance 为最短距离
        int v=t.second,distance=t.first;

        // 若 v 被访问过了，则不用进行松弛了
        if(flag[v])continue;
        flag[v]=true;

        // 遍历顶点v的所有邻接点，这里的总时间复杂度为O(m)
        for(int i=h[v];i!=-1;i=ne[i])
        {
            // 邻节点j
            int j=e[i];
            // 更新邻节点的最短距离
            if(dist[j]>distance+w[i])
            {   
                dist[j]=distance+w[i];
                // 堆插入元素是插在队尾，然后进行上浮操作，时间复杂度为O(logn)
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    int t;
    scanf("%d",t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        // 初始化邻接表
        memset(h,-1,sizeof h);
        memset(w,0,sizeof w),memset(e,0,sizeof e),memset(ne,0,sizeof ne);
        idx=0;
        while(m--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }

        printf("%d\n",dijkstra(0));
    }
    
    return 0;
}