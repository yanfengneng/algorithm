#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> father; // 父亲
    vector<int> len;    // 树的大小
    int cnt=0;          // 联通量的个数
public:
    UnionFind(int n)    // 构造函数初始化对象
    {
        father.resize(n+1),len.resize(n+1);
        cnt=n;
        for(int i=1;i<=n;++i)
        {
            father[i]=i;    // 初始化时父节点指向本身
            len[i]=1;       // 初始化时每个树大小为1
        }
    }

    int find(int x)     // 查询树的根
    {
        // 在查询所有父节点过程中，顺便进行路径压缩
        while(father[x]!=x)
        {
            father[x]=father[father[x]];
            x=father[x];
        }
        return x;
    }

    void merge(int x,int y) // 合并x和y所属的集合
    {
        x=find(x),y=find(y);
        if(x==y)return;     // x和y为同一集合不需要合并
        // 按秩进行合并，小秩向大秩合并
        if(len[x]<len[y])
        {
            father[x]=y;
            len[y]+=len[x];
        } 
        else
        {
            father[y]=x;
            len[x]+=len[y];
        }
        cnt--;       
    }

    int count(){return cnt;}
};

int n,m;

int main()
{
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        UnionFind uf(n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            uf.merge(a,b);
        }
        cnt++;
        printf("Case %d: %d\n",cnt,uf.count());
    }
    return 0;
}