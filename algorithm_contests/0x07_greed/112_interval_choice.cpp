#include <bits/stdc++.h>
using namespace std;

int n,d;
const int N = 1e3+10;
const double eps = 1e-6, INF = 1e10;
#define x first
#define y second
using PDD = pair<double,double>;
PDD q[N];

// 思路：将小岛转换为x轴上的区间，题目要求的是雷达的最小数目，也就是转换为在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点
int main()
{
    cin>>n>>d;

    // 表示雷达能否探索到所有的小岛
    bool success=true;
    for(int i=0;i<n;++i)
    {
        int x,y;cin>>x>>y;
        if(y>d)// 雷达探索失败，直接跳出循环了
        {
            success=false;
            break;
        }
        // 利用勾股定理将点转换为在x轴上的区间，以(x,y)为圆心，d为半径在x轴上找两个交点就行
        auto len=sqrt(d*d-y*y);
        q[i]={x-len,x+len};
    }
    if(!success)puts("-1");
    else
    {
        // 将所有区间按右端点由小到大进行排序
        sort(q,q+n,[](const auto& a,const auto& b){
            return a.y<b.y;
        });

        // 开始从前往后依次枚举每个区间
        int res=0;
        double last=-INF;
        for(int i=0;i<n;++i)
        {
            // 当前区间不包括上一个区间中的左端点，表示新找到了一个区间，则更新last为新区间的右端点即可
            if(eps+last<q[i].x){
                res++;
                last=q[i].y;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}