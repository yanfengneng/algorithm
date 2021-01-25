#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5+10;

int n,m;

// e[i]=j表示i的邻节点为j
int h[N],e[N],ne[N],w[N],idx=0;

// 最短距离数组和顶点标记数组
// cnt表示当前最短路的长度
int dist[N],cnt[N];
bool flag[N]={0};

// a->b 的权值为 c
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}


bool spfa()
{
    // 初始化dist
    memset(dist,0,sizeof dist);
    
    queue<int> q;
    // 由于负环不一定是从1号点开始的，每个点都有可能，所以把每个点都放在队列里面
    for(int i=1;i<=n;++i)
    {
        flag[i]=true,q.push(i);
    }

    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        // 点t出队列了，标记为false
        flag[t]=false;

        // 更新 t 的所有邻边，i->j 的权值为 w[i]
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            // 可松弛，则进行更新
            if(dist[j]>dist[t]+w[i])
            {
                // 每次更新，同时更新cnt
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;

                // 最短路径长度大于等于n了，表示存在负环了
                // 即如果第n次任然更新了，则存在负环
                if(cnt[j]>=n)return true;
                // 若j不在队列中，则加入队列
                if(!flag[j])
                {
                    q.push(j);
                    flag[j]=true;
                }
            }
        }
    }

    return false;
}

int main()
{
    // 初始化邻接表顶点
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);

    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }

    if(spfa())puts("Yes");
    else puts("No");

    return 0;
}