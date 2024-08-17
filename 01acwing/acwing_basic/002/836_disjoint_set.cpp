#include <iostream>
using namespace std;

const int N = 1e5+10;
int fa[N],rk[N];

//  初始化n个元素
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        // rk表示树的高度
        rk[i]=0;
    }
}

// 查询x的根
int find(int x)
{
    if(fa[x]==x)return x;
    // 在查询根节点的过程中顺带进行路径压缩
    else return fa[x]=find(fa[x]);
}

// 合并x和y所属的集合
void merge(int x,int y)
{
    // 先找到x、y所对应的根，然后判断是不是同一集合，在进行合并与否
    x=find(x),y=find(y);
    if(x==y)return;
    // 进行按秩合并：小树向大树合并
    if(rk[x]<rk[y])fa[x]=y;
    else
    {
        fa[y]=x;
        // x、y的高度相同，则合并之后高度+1
        if(rk[x]==rk[y])rk[x]++;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    // 进行初始化
    init(n);

    char op[2];
    int a,b;
    while(m--)
    {
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M')merge(a,b);
        else
        {
            if(find(a)==find(b))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}