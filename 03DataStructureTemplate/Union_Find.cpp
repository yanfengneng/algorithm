#include <iostream>
#include <vector>

using namespace std;

class UF
{
private:
    //count记录联通分量的数量。parent用来表示父亲节点，即树的双亲表示法。rank用来表示树的高度。
    int count;
    vector<int> parent,rank;
public:
    UF(int n)
    {
        this->count=n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    // 查询树的根
    int find(int x)
    {
        if(parent[x]==x)return x;
        // 递归查询x的根，顺便进行路径压缩
        else parent[x]=find(parent[x]);
    }

    // 合并 x 和 y 所属的集合
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        // x y 根相同，不需要合并
        if(x==y)return;

        // rank小的向rank大的连边
        if(rank[x]<rank[y])parent[x]=y;// x的父节点连向y
        else{
            parent[y]=x;
            // x y 高度相同，则在连边之后树的高度+1
            if(rank[x]==rank[y])rank[x]++;
        }
        // 连通分量-1
        count--;
    }


    // 判断 x 和 y 是否相互连通
    bool connected(int x,int y)
    {
        return find(x)==find(y);
    }

    // 输出联通分量数
    int size()
    {
        return this->count;
    }
};

int main()
{
    UF uf(10);
    cout<<uf.size()<<endl;
    uf.unite(1,2);
    cout<<uf.size()<<endl;
    return 0;
}