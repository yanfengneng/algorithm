#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 1e5+10;
using PII = pair<int,int>;
PII q[N];
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;

    // 按右端点由小到大进行排序
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.y<b.y;
    });

    int res=1,last=q[0].y;
    for(int i=1;i<n;++i){
        // 上一个区间的右端点没有被包含在当前区间内，则更新last为当前区间的右端点，区间数+1
        if(last<q[i].x){
            res++;
            last=q[i].y;
        }
    }
    cout<<res<<endl;
    return 0;
}