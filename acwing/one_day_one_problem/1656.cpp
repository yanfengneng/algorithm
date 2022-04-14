#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using LL = long long;
using PLL = pair<LL,LL>;
const int N = 1e5+10;

PLL q[N];
int n,m;

bool check(LL mid)
{
    int cnt=1,pos=q[0].x;
    int i=0;
    while(i<m){
        // 判断pos+mid能否跳过第i个区间
        // 若不能，则下次的起点为pos+mid与第i个区间的起点的较大值，这样保证到达第i个区间的距离大于等于mid且落在第i个区间上
        if(pos+mid<=q[i].y){
            pos=max(pos+mid,q[i].x);
            cnt++;
        }
        // 若能，则寻找下一个不能跳过的区间
        else{
            while(i<m&&pos+mid>q[i].y)i++;
            if(i>=m)break;
            pos=max(pos+mid,q[i].x);
            cnt++;
        }
    }
    return cnt>=n;
}


// 思路：二分答案转换为判定
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>q[i].x>>q[i].y;
    
    sort(q,q+m);
    
    LL l=0,r=1e18;
    while(l<r)
    {
        LL mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    
    return 0;
}