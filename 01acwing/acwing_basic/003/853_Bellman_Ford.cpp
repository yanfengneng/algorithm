#include <iostream>
#include <cstring>
using namespace std;

int n,m,k;

const int N = 510,M = 1e4+10;
int dist[N],backup[N];

// 顶点a到顶点b的权值为w
struct Edge
{
    int a,b,w;
}edges[M];

int bellman_ford(int s)
{
    // 初始化距离
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;

    // 这里k次遍历表示从1号点到n号点不超过k条边的最短距离
    for(int i=0;i<k;++i)
    {
        // 将dist备份到backup中
        memcpy(backup,dist,sizeof dist);

        // 遍历所有的边
        for(int j=0;j<m;++j)
        {
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            // 更新b的最短距离，为了防止发生串联现象，要使用上一次的dist
            // 因为点举有传递性，而边数又是固定的，所以只能只用上一次的dist
            dist[b]=min(dist[b],backup[a]+w);
        }
    }

    // 无穷点也可能更新为小一点的无穷，所以要判断一下
    if(dist[n]>0x3f3f3f/2)return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edges[i]={x,y,z};
    }

    if(bellman_ford(1)==-1)puts("impossible");
    else printf("%d\n",dist[n]);

    return 0;
}