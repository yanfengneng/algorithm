#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5+10;

int n,m;

// e[i]=j表示i的邻节点为j
int h[N],e[N],ne[N],w[N],idx=0;

// 最短距离数组和顶点标记数组
int dist[N];
bool flag[N]={0};

// a->b 的权值为 c
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

// 计算从源点s出发的最短路
int spfa(int s)
{
    // 初始化dist
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    
    // 初始化队列和s点标记
    // 队列中存放的是距离变小的点，且队列中的点不能重复，要用flag来标记
    queue<int> q;
    q.push(s);
    // flag存的是当前这个点是否在队列之中，防止队列之中存储重复的点
    flag[s]=true;

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
                dist[j]=dist[t]+w[i];

                // 若j不在队列中，则加入队列
                if(!flag[j])
                {
                    q.push(j);
                    flag[j]=true;
                }
            }
        }
    }

    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
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

    int t = spfa(1);

    if(t==-1)puts("impossible");
    else printf("%d\n",t);

    return 0;
}