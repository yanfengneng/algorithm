#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int N = 1e5+10;

// 邻接表，idx表示当前可以使用的节点编号
int h[N],e[N],ne[N],idx=0;

// q为队列，d为记录顶点的入度的数组
int q[N],d[N];

// 插入边ab
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topSort()
{
    // hh为队头，tt为队尾
    int hh=0,tt=-1;

    // 将入度为 0 的点加入队列
    for(int i=1;i<=n;++i)
        if(!d[i])q[++tt]=i;

    // 开始bfs
    while(hh<=tt)
    {
        // 获得队头元素并将队头元素出队
        int t=q[hh++];

        // 删掉t出发的所有邻接边
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            // 顶点 j 的入度减 1
            d[j]--;
            // 若入度减为0了，则加入队列
            if(!d[j])q[++tt]=j;
        }
    }
    // tt等于n-1的话，表示队列已经进了n个顶点了，表示这是一个有向无环图，否则就不是无环图
    // 如果存在环的话，拓扑序列中的顶点个数必然小于n，因此环中各点的入度必定不为1，那么就无法进行队列，也就无法存储在拓扑序列中。这样表明拓扑序列中元素小于n，必然存在环。
    return tt==n-1;
}

int main()
{
    scanf("%d%d",&n,&m);
    // 初始化邻接表的链表顶点
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        // 顶点b的入度+1
        d[b]++;
    }

    if(topSort())
    {
        // 由于队列并非真正将队列中的元素出队了，所以队列中保存的次序为top序列，现在只需要把它打印出来就好了
        for(int i=0;i<n;++i)printf("%d ",q[i]);
        puts("");
    }
    else puts("-1");
    return 0;
}