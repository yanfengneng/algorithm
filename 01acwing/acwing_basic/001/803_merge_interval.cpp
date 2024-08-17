#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<PII> segs;

void merge(vector<PII>& segs)
{
    vector<PII> res;
    // 这样排序也没有问题，也可以找到不重复的区间数
    // pair的排序是：若左端点不同，则按左端点由小到大排序；若左端点相同，则按右端点由小到大排序
    sort(segs.begin(),segs.end());

    int st=-2e9,ed=-2e9;
    // 从前之后扫描所有的区间
    for(auto seg:segs)
    {
        // 维护区间的右端点小于本区间的左端点，表示找到一个新的区间
        if(ed<seg.first)
        {
            if(st!=-2e9)res.push_back({st,ed});
            st=seg.first,ed=seg.second;
        }
        // 维护区间和本区间是有交集的，则更新右端点，即合并区间
        else
        {
            ed=max(ed,seg.second);
        }
    }

    // 也要把最后这个区间加到答案里面去
    // 这里加if判断是防止我们输出了一个空的区间
    if(st!=-2e9)res.push_back({st,ed});

    // 更新segs
    segs=res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    // 合并区间
    merge(segs);

    cout<<segs.size()<<endl;

    return 0;
}