#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 5e5+10;
using PII = pair<int,int>;
// 存储<区间，奶牛编号>
pair<PII,int> cows[N];
int id[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cows[i].x.x>>cows[i].x.y;
        cows[i].y=i;
    }

    // 按左端点由小到大进行排序
    sort(cows,cows+n,[](const auto& a,const auto& b){
        return a.x.x<b.x.x;
    });

    // 堆中存放的元素为<当前分组内区间右端点的最小值，分组编号>
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    // 按左端点从小到大枚举即可
    for(int i=0;i<n;++i)
    {
        // 堆为空或者堆中右端点的最小值大于等于当前区间的左端点，表示区间相交，需要新开一个分组，再把当前区间放进去
        if(heap.empty()||heap.top().x>=cows[i].x.x)
        {
            // 新区间的右端点，分组编号
            PII stall={cows[i].x.y,heap.size()};
            // 奶牛i被存放到分组stall.y中
            id[cows[i].y]=stall.y;
            // 添加新的分组
            heap.push(stall);
        }
        //  否则表示当前区间可以添加到右端点最小值的分组中，则将右端点最小值进行更新为当前区间的右端点
        else
        {
            auto stall=heap.top();heap.pop();
            // 更新合并区间后新的右端点
            stall.x=cows[i].x.y;
            // 奶牛i被存放在分组stall.y中
            id[cows[i].y]=stall.y;
            // 将更新右端点之后的分组，重新添加到堆中
            heap.push(stall);
        }
    }

    cout<<heap.size()<<endl;
    for(int i=0;i<n;++i)cout<<id[i]+1<<endl;
    return 0;
}