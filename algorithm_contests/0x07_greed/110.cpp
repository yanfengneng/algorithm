#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 2510;
PII cows[N];

int n,m;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>cows[i].first>>cows[i].second;
    map<int,int> spfs;
    for(int i=0;i<m;++i){
        int spf,cover;
        cin>>spf>>cover;
        spfs[spf]+=cover;
    }
    sort(cows,cows+n);
    int res=0;
    // 为了方便在平衡树中找最大最小值，我们加入两个哨兵
    spfs[0]=spfs[1001]=n;
    for(int i=n-1;i>=0;i--){
        auto cow=cows[i];
        // upper之后再减1就找到小于等于maxSPF的最大数了
        auto spf=spfs.upper_bound(cow.second);
        spf--;
        if(spf->first>=cow.first&&spf->first<=cow.second){
            res++;
            if(--spf->second==0)spfs.erase(spf);
        }

    }
    cout<<res<<endl;
    return 0;
}