#include <bits/stdc++.h>

using namespace std;

vector<int> a(2e5+10,0),cnt(1e6+10,0);
set<int> visited;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    sort(a.begin(),a.begin()+n);

    // 表示数组的最大值，我们需要开个maxA大的数组来将a[i]的倍数进行标记，表示可被整除，类似素筛法
    int maxA=a[n-1];
    for(int i=0;i<n;++i)
    {
        // 对同一元素出现多次，采用set来记录，表示可整除
        if(visited.count(a[i])>0)cnt[a[i]]=1;
        else visited.insert(a[i]);

        // 数组值为1表示能被a[i]整除
        for(int j=2*a[i];j<=maxA;j+=a[i])cnt[j]=1;
    }

    int res=0;
    // cnt[a[i]]==0的表示不会被任何元素整除的，等于1的为可被其他元素整除
    for(int i=0;i<n;++i)
    {
        if(!cnt[a[i]])res++;
    }
    cout<<res<<endl;
    return 0;
}