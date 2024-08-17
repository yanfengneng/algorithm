#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
// h[u]=idx表示顶点u的第一条邻接表的编号是idx；数组e和数组ne的下标是边的编号，对于顶点u，它的所有邻边的编号不一定是连续的，与建图添加边的顺序有关
// 数组e[idx]=b存放的是当前边idx的终点是b；ne[idx]=eidx表示当前边idx的邻接边的编号为eidx；idx表示当前可以使用边的编号
int h[N],e[N],ne[N],idx=0;
// 存放每个结点的父节点编号
bool has_fa[N];
// 快乐数组；状态f[u][0]表示从所有以u为根的子树选择，并且不选u这个点的方案的快乐最大值；状态f[u][1]表示从所有以u为根节点的子树中选，并且选择u这个点的方案的快乐最大值
int happy[N],f[N][2];
int n;

// 头插法插入边a->b
void add(int a,int b)
{
    // 当前边idx的终点顶点是b；当前边的邻接边指向顶点a的第一条邻接边的编号；然后顶点a的第一条邻接边指向当前新建边的编号
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

// 求节点u快乐最大值
void dfs(int u)
{
    // 当前选择节点u
    f[u][1]=happy[u];
    // 开始遍历u的所有邻节点，这里的i是指边的编号
    for(int i=h[u];i!=-1;i=ne[i])
    {
        // 获得顶点u的邻节点j
        int j=e[i];
        // 先递归计算顶点j为根节点的所有方案快乐最大值，选顶点j与不选顶点j两种方案的最大值
        dfs(j);
        // 不选顶点u，则选择u的邻节点j的子树的两种方案，状态的第二维0表示不选顶点j的所有方案快乐最大值，1表示选顶点j的所有方案快乐最大值
        f[u][0]+=max(f[j][0],f[j][1]);
        // 选择顶点u，就只能选择不选顶点j的所有方案最大值了，进行累加即可
        f[u][1]+=f[j][0];
    }
}

int main()
{
    cin>>n;
    // 这里的顶点编号必须从1开始存，因为题目的顶点编号从1开始的
    for(int i=1;i<=n;++i)cin>>happy[i];

    memset(h,-1,sizeof h);
    memset(has_fa,0,sizeof has_fa);
    // 输入n-1条边，构建邻接表
    for(int i=0;i<n-1;++i)
    {
        int a,b;cin>>a>>b;
        // b是a的上司，即b->a
        add(b,a);
        has_fa[a]=true;// a有父节点
    }

    // 从顶点1开始寻找根节点，也就是没有父节点的那个节点就是根节点了
    int root=1;
    while(has_fa[root])root++;

    // 开始进行树形dp
    dfs(root);
    // 最后结果为f[root][0] f[root][1]中较大值，表示选root与不选root方案的最大快乐值
    cout<<max(f[root][0],f[root][1])<<endl;
    return 0;
}