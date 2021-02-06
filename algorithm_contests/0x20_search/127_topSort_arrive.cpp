#include <iostream>
#include <bitset>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e4+10;

// 邻接表，e存放是的邻节点，ne存放的是邻节点的节点id，idx为当前可用的节点id
int h[N],e[N],ne[N],idx=1;

// 顶点的入度
int d[N],skt[N];

// f(x)表示第i位为1表示x能到i点，0表示不能到i点
bitset<N> f[N];

int n,m;

void add(int a,int b)
{
    // 头插法
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void topsort()
{
    queue<int> q;
    // 将度为0的点加入队列
    for(int i=1;i<=n;++i)
        if(!d[i])q.push(i);

    int k=0;
    // 开始bfs
    while(!q.empty())
    {
        // 入度为0的点出队列，也为topsort的点，加入stk
        int t=q.front();q.pop();
        skt[k++]=t;
        // 删除t指向的所有边，即邻节点的入度-1，为0时加入队列
        for(int i=h[t];i;i=ne[i])
        {
            int j=e[i];
            if(--d[j]==0)q.push(j);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    // 若用0初始化的话，idx要从1开始，如果idx从0开始的话，就会发生错误。因为0作为节点编号，又作为结束的标值冲突了，所以要从0开始。
    // 若用-1初始化的话，我们用-1作为结束的标值，idx从0开始作为节点的编号，这样不会发生冲突。
    // 即 h 初始化为 -1，idx=0；h 初始化为0，idx=1。这样在遍历邻节点的时候，for循环结束的时候，才不会发生冲突。
    memset(h,0,sizeof h);

    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        d[y]++;
    }
    // 进行topsort
    topsort();

    // 获得topsort后，我们倒序遍历计算f[x]
    for(int i=n-1;i>=0;--i)
    {
        // 由于可能存在重边，所以这里的x可能为0
        int x=skt[i];
        // 自己可以到自己，所以点数为1
        f[x][x]=1;
        // 遍历 x 的邻节点，由于是从后向前遍历的，所以后面顶点的f函数已经计算了
        // 如x->y，我们先计算出了f[y]，然后我们从后向前遍历到x时，我们把x到达点并上f[y]
        // 即 {x}∪{f[y]}∪{所有x的邻节点}，就是x能到达的所有点了
        for(int k=h[x];k;k=ne[k])
            f[x]|=f[e[k]];
    }

    for(int i=1;i<=n;i++)printf("%d\n",f[i].count());
    return 0;
}