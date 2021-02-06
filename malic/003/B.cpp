#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int a[N],b[N];
int n;

// 猴群最重的猴子重量为 x，次重的为 y。 抓走 x 的那天,y 可当大王，其它天都是 x 当大王。
int main()
{
    /*cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    memcpy(b,a,sizeof(int)*n);
    sort(b,b+n);

    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[n-1])cout<<b[n-1]<<endl;
        else cout<<b[n-2]<<endl;
    }*/

    // 除了用排序做之外，可以边出入边记录最大值和此最大值
    cin>>n;
    int x=-1,y=-1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>x)// 更新最大值和次最大值
        {
            y=x;
            x=a[i];
            continue;
        }
        // 更新次最大值
        if(a[i]>y)y=a[i];
    }

    for(int i=0;i<n;++i)
    {
        // 判断最大值x是否被抓走了，被抓走了就y做猴王，没被抓走就x做猴王
        if(a[i]!=x)cout<<x<<endl;
        else cout<<y<<endl;
    }
    return 0;
}