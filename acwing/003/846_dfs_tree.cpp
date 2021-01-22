#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10,M = 2*N;
int n;
// idx表示每个节点对应一个唯一的编号，即当前可以使用的节点编号
int h[N],e[M],ne[M],idx=0;
// 标记顶点使用过没有
bool flag[N]={0};

// 记录全局的答案
int ans=N;

// 增加边a->b
void add(int a,int b)
{
    // 头插法，idx为新节点的编号
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

// 以u为根的子树中点的数量
int dfs(int u)
{
    // 标记点u已经被搜过了
    flag[u]=true;

    // sum：u为根也算一个点，res：把这个点删除之后每个连通块大小的最大值
    int sum=1,res=0;

    // 遍历u的邻节点
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!flag[j])
        {
            // 用s来表示当前这个子树的大小，当前这个子树也算是连通块
            int s=dfs(j);
            // 当前子树也算一个连通块
            res=max(res,s);
            // 当前这个子树，也算节点i为根子树的一部分
            sum+=s;
        }
    }
    // n-sum为子树上面一坨，取了max后，res为连通块最大的点数了
    res=max(res,n-sum);
    // 总答案娶一个min
    ans=min(ans,res);
    // 返回该子树的
    return sum;
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}