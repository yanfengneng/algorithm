#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10,M =2e5+10;

// 邻接表存储图。e存的是邻节点的编号。ne存的是next指针，即下一个节点的编号。idx表示当前可使用的节点编号。
int h[N],e[M],ne[M],idx=0;
// 顶点i的颜色
int color[N];
int n,m;

void add(int a,int b)
{
    // 头插法
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)
{
    // 先修改颜色
    color[u]=c;

    // 将 u 的邻节点进行染色
    for(int i=h[u];i!=-1;i=ne[i])
    {   
        int j=e[i];
        
        // 若 j 号点没有被染色的话，则染成下一种颜色
        if(!color[j])
        {
            // 存在负环，则返回false
            if(!dfs(j,3-c))return false;
        }
        // 邻节点被染了相同的颜色，矛盾了
        else if(color[j]==c)return false;
    }

    return true;
}

int main()
{
    // 初始化邻接表顶点数组
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);

    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        // 无向图，建立正反两条边
        add(a,b),add(b,a);
    }

    bool flag=true;
    for(int i=1;i<=n;++i)
    {
        // 如果i号点没有被染色，就把它染成1号色
        if(!color[i])
        {
            // 如果没染成功，则存在负环，即不能进行二分匹配
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
        }
    }

    if(flag)puts("Yes");
    else puts("No");

    return 0;
}