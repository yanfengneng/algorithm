#include <iostream>
#include <cstring>
using namespace std;

const int N =1e5+10;
// 邻接表
int h[N],e[N],ne[N],idx=0;
// 距离和队列
int dist[N],q[N];

int n,m;

void add(int a,int b)
{
    // 头插法
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int bfs()
{
    // tt正常初始化为-1的，因为要把1号点加入队列，然后变为0了
    // tt为队尾非空元素
    int tt=0,hh=0;
    q[0]=1;

    // 初始化距离，-1表示没有被遍历过
    memset(dist,-1,sizeof dist);
    // 1号点的距离为0
    dist[1]=0;
    
    // 开始bfs
    while(hh<=tt)
    {
        // 取队头元素，并将队头元素出队列
        int t=q[hh++];

        for(int i=h[t];i!=-1;i=ne[i])
        {
            // j 表示当前点可以到的点
            int j = e[i];
            // 若 j 号点没有被扩展过的话，就扩展一下
            if(dist[j]==-1)
            {
                // 更新层数
                dist[j]=dist[t]+1;
                // 加入队列
                q[++tt]=j;
            }
        }
    }
    return dist[n];
}

int main()
{
    cin>>n>>m;
    // 初始化临界表的头节点
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        // 这里为有向图
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}