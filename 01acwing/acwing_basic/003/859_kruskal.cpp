#include <iostream>
#include <algorithm>
using namespace std;

int n,m;

const int N = 2e5+10;
int fa[N];

// 用结构体把每条边存下来
struct Edge
{   
    int a,b,w;

    // 重载一下小于号，方便用来排序
    bool operator < (const Edge& W)const
    {
        return w<W.w;
    }
}edges[N];

int  find(int x)
{
    if(x!=fa[x])return fa[x]=find(fa[x]);
    else return x;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;++i)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    // 排序所有边
    sort(edges,edges+m);

    // 初始化并查集
    for(int i=1;i<=n;++i)fa[i]=i;

    // res为最小生成树的权重，cnt计算最小生成树的边数
    int res=0,cnt=0;

    // 枚举一下每条边
    for(int i=0;i<m;++i)
    {
        int a=edges[i].a, b=edges[i].b, w=edges[i].w;

        // 判断a，b是否来自两棵不同的树
        a=find(a),b=find(b);

        if(a!=b)
        {
            // 合并两棵树
            fa[a]=b;
            res+=w;
            cnt++;
        }
    }

    if(cnt<n-1)puts("impossible");
    else printf("%d\n",res);

    return 0;
}