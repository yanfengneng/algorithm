#include <iostream>
using namespace std;

const int N = 1e5+10;

int n,m;
// size表示每个集合点的数量，只有根节点的size才有意义
int fa[N],size[N];

// 初始化n个元素
void init(int n)
{
    // 初始化时每个节点指向自身，且每个集合的大小为1
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        size[i]=1;
    }
}

// 查询树的根，在查询x的过程中顺带进行路径压缩
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);// 路径压缩
}

// 合并x和y所属的集合
void merge(int x,int y)
{
    x=find(x),y=find(y);
    // x和y是同一集合，也需要合并，无非多几条冗余的边呗
    if(x==y)return;
    // 按秩合并，小秩向大秩合并
    if(size[x]<size[y])
    {
        // x集合合并到y集合中，y集合的点数增加
        fa[x]=y;
        size[y]+=size[x];
    }
    else
    {
        // y集合合并到x集合中，x集合的点数增加
        fa[y]=x;
        size[x]+=size[y];
    }  
}

int main()
{
    scanf("%d%d",&n,&m);

    // 初始化集合
    init(n);

    char op[5];
    int a,b;
    while(m--)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else if(op[1]='1')
        {
            scanf("%d%d",&a,&b);
            // Puts和printf功能类试，只是自动添加换行符罢了
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
        else
        {
            scanf("%d",&a);
            // a所在集合中的点的个数
            printf("%d",size[find(a)]);
        }
    }
    return 0;
}