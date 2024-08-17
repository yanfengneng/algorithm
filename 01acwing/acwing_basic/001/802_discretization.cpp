#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int n,m;
const int N=3e5+10;
// 数组a表示存的是数，数组s表示前缀和
int a[N],s[N];
// alls存的是所有离散化的值
vector<int> alls;
// all用来记录x和c的，表示在x位置上加上c呗。query表示用来查询的
vector<PII> add,query;

// 二分：找到>=x的最小位置
int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    // 把x映射到1，2，3...n，因为前缀和是从1开始的
    return r+1;
}
vector<int>::iterator unique(vector<int>& a)
{
    int j=0;
    // 遇到不同的元素直接覆盖在数组前面
    for(int i=0;i<a.size();++i)
        if(!i||a[i]!=a[i-1])
            a[j++]=a[i];
    return a.begin()+j;
}
// 离散化的本质，是映射，将间隔很大的点，映射到相邻的数组元素中，来减少对空间的需求量，也减少计算量
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int x,c;
        cin>>x>>c;
        // 记录：在位置x上加上c
        add.push_back({x,c});
        // 将下标x加入到离散化数组里面去
        alls.push_back(x);
    }

    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});

        // 将左右区间相加到离散化数组中，这里对后面离散化的数组加上c没有影响
        // 也对求前缀和没有影响，因为该位置所对应的值为0
        alls.push_back(l);
        alls.push_back(r);
    }

    // 先排序，再去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    // 处理插入
    for(auto item:add)
    {
        // x为离散化之后的数组下标，再该下标所位置上加上要加的数c
        int x=find(item.first);
        a[x]+=item.second;
    }

    // 预处理前缀和
    for(int i=1;i<=alls.size();++i)s[i]=s[i-1]+a[i];

    // 处理询问
    for(auto item:query)
    {
        // [l,r]为离散化的左右区间下标
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}