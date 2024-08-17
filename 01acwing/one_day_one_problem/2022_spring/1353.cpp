#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n,h[N];

/*
由于最终山峰的高度差要控制在17以内，所以我们直接枚举所有长度为17的区间，然后计算将所有山峰移到这些区间所花费的最小代价
所有区间范围为[0,17]、[1,18]...[83,100]，区间的起点不会小于0也不会大于100。若区间起点小于0，则将山峰以到小于0位置的代价明显
大于将山峰移到为0的位置，所以不用考虑区间起点小于0的位置了；同理也不用考虑终点大于100的位置了
*/

int sqr(int x)
{
    return x*x;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>h[i];
    
    // 数据范围的极限值为100*100*1000=1e7
    int res=1e7+10;
    // 枚举这84个区间，计算每个区间的花费，并更新res
    for(int i=0;i<=83;++i){
        int cost=0;
        // 开始计算所有山峰移到[i,i+17]这个区间的代价
        for(int j=0;j<n;++j){
            if(h[j]<i)cost+=sqr(i-h[j]);
            else if(h[j]>i+17)cost+=sqr(h[j]-i-17);
        }
        res=min(res,cost);
    }
    cout<<res<<endl;
    return 0;
}