#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int fa[N],len[N];

// 初始化
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        len[i]=1;
    }
}

// 查询根，并进行路径压缩
int find(int x)
{
    if(fa[x]!=x)return fa[x]=find(fa[x]);
    else return x;
}

// 合并x和y所属的集合，并按秩合并
void merge(int x,int y)
{
    x=find(x),y=find(y);
    // x y 属于同一组，不用进行合并
    if(x==y)return;
    // 小秩向大秩合并
    if(len[x]<len[y])
    {
        fa[x]=y;    // 根x的父节点指向y
        len[y]+=len[x];
    }
    else
    {
        fa[y]=x;    // 根y的父节点指向x
        len[x]+=len[y];
    }
}

int n,m;

int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        init(n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int res=0;
        // 每个联通量的根只有一个，我们遍历n个点，统计根的个数就是联通量的个数
        for(int i=1;i<=n;++i)
            if(i==find(i))res++;
    
        printf("Case %d: %d\n",++cnt,res);
    }
    return 0;
}