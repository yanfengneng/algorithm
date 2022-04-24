#include <bits/stdc++.h>
using namespace std;


const int N = 110;
// size表示每个集合点的数量，只有根节点的size才有意义
int fa[N],s[N];

// 初始化n个元素
void init(int n)
{
    // 初始化时每个节点指向自身，且每个集合的大小为1
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        s[i]=1;
    }
}

// 查询树的根，在查询x的过程中顺带进行路径压缩
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);// 路径压缩
}

int n;
int a[N],b[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    // 数组b中存放元素x被存放的位置i，便于后续的在数组a中找到有向环的边
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        b[x]=i;
    }

    // 初试化并查集
    init(n);

    // 开始进行合并集合，也就是找圆环
    for(int i=1;i<=n;++i){
        // b[x]的值表示x在数组a中的位置，a[b[x]]的值表示a数组中需要与x进行交换的元素
        int x=a[i],y=a[b[x]];
        if(find(x)!=find(y)){
            // 将y所在集合合并到x所在集合中
            s[find(x)]+=s[find(y)];
            // 将y所在集合中根节点改为x所在集合中的根节点
            fa[find(y)]=fa[find(x)];
        }
    }

    int cnt=0,mx=0;
    for(int i=1;i<=n;++i){
        // 找到集合且集合大小大于1，则进行计数和更新最大长度
        if(fa[i]==i&&s[i]>1){
            cnt++;
            mx=max(mx,s[i]);
        }
    }
    if(!cnt)mx=-1;
    cout<<cnt<<" "<<mx<<endl;
    return 0;
}