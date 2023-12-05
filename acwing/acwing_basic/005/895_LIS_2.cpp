#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);

    // f用来存储存放子序列的结尾最小值，如f[i]=c，表示长度为i+1的递增子序列的结尾最小值为c
    // 下标和长度有1的偏差
    vector<int> f;
    for(int i=0;i<n;++i)
    {
        // 这里在f中寻找大于等于a[i]的元素的最小位置为pos，同时pos也是下标，即f[pos]=c，c是长度为pos+1的所有上升子序列的结尾最小值
        auto pos=lower_bound(f.begin(),f.end(),a[i]);
        // 若找到了>=a[i]的最小位置pos，则更小值a[i]用来更新c，这样可以让长度为pos+1所有上升子序列的结尾最小值更小，因为只有结尾数越小，上升子序列的长度越大
        if(pos!=f.end())*pos=a[i];
        // 若没有找到>=a[i]的最小位置pos，则添加a[i]到f的尾部，表示a[i]为长度为f.size()的所有上升子序列的结尾最小值
        else f.push_back(a[i]);
    }
    // f[n-1]=c表示长度为n的所有上升子序列的结尾最小值为c，此时直接返回n，表示所有最长上升子序列的长度最大值
    cout<<f.size()<<endl;
    return 0;
}