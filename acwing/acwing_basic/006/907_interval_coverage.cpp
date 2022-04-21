#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
const int N = 1e5+10;
PII q[N];

int n;
int st,ed;

int main()
{
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;
    // 先按左端点由小到大进行排序
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x<b.x;
    });
    // 从前往后枚举每一个区间
    int res=0;
    bool success = false;
    // 这里的[i,j]是使用的双指针，可以将时间复杂度控制在O(n)，因为每次寻找区间都是i与j都是同时在[0,n-1]上移动的，并且ij不重复，所以是线性的复杂度
    for(int i=0;i<n;++i){
        int j=i,r=-2e9;
        // 寻找能包含线段左端点的区间，并且在这些区间中选择一个右端点最大的区间，并将st更新为右端点最大值
        while(j<n&&q[j].x<=st){// 当前区间的左端点小于等于线段的左端点，表示可以包含线段的左端点
            r=max(r,q[j].y);
            j++;
        }
        // 没有寻找合适的区间包含线段左端点，表示不存在满足题目条件的区间包含线段了，直接跳出循环即可
        if(r<st){
            res=-1;
            break;
        }
        // 区间数+1
        res++;
        // 所有包含线段的区间找完了，直接跳出循环
        if(r>=ed){
            success=true;
            break;
        }
        // 更新线段的起始端点为满足区间的最大右端点
        st=r;
        // 这里使用j-1是因为最后跳出while循环的时候 q[j].x>st 了，而上一个区间q[j-1]才包含st，所以要使用j-1，这样保证区间无间隔
        i=j-1;
    }
    if(!success)res=-1;
    cout<<res<<endl;
    return 0;
}