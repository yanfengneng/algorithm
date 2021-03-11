#include <bits/stdc++.h>
using namespace std;

using LL =long long;

struct node
{
    // 半径、高、侧面积
    LL r,h,s;
}a[1010];

int n,m;

bool cmp(node x,node y)
{
    return x.s>y.s;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i].r>>a[i].h;
        a[i].s=2*a[i].r*a[i].h;
    }

    // 枚举最大可视化表面积，先给侧面积排个序，便于贪心的选择m-1个最大的侧面积
    sort(a,a+n,cmp);
    LL res=0;
    // 固定选择 圆柱i 的底面积+侧面积，然后贪心的选择前m-1个最大的侧面积
    for(int i=0;i<n;++i)
    {
        LL sum=a[i].s+a[i].r*a[i].r;
        int cnt=1;
        for(int j=0;j<n&&cnt<m;++j)
        {
            // 圆柱不能重复，同时之后的圆柱的底面积必须要比第i个圆柱的底面积要小
            if(i==j||a[j].r>a[i].r)continue;
            sum+=a[j].s;
            cnt++;
        }
        if(cnt==m)res=max(res,sum);
    }
    cout<<res<<endl;
    return 0;
}