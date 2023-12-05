#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
const int N = 1e5+10;
PII q[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;

    // 按左端点由小到大进行排序
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x<b.x;
    });

    // 创建小根堆，来保存每个分组中区间的右端点的最小值
    priority_queue<int,vector<int>,greater<int>> heap;

    // 由于是按左端点由小到大进行枚举的，所以左端点严格不存在交集，这样每次就仅需判断堆中右端点最小值与当前区间的左端点大小即可
    for(int i=0;i<n;++i)
    {
        // 若堆为空或者堆中右端点的最小值大于等于当前区间的左端点，表示当前区间与所有分组存在交集，则需要开辟一个新组，并把当前区间的右端点添加进去
        if(heap.empty()||heap.top()>=q[i].x)heap.push(q[i].y);
        // 否则表示当前区间可以添加到右端点最小值的分组中，则将右端点最小值进行删除，并添加当前区间的右端点
        else{
            int t=heap.top();heap.pop();
            heap.push(q[i].y);
        }
    }
    cout<<heap.size()<<endl;
    return 0;
}