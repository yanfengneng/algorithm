#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    long long res=0;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;++i)
        mp[a[i]+i]++;

    for(int j=1;j<=n;++j)
        if(mp.count(j-a[j]))
            res+=mp[j-a[j]];
    
    printf("%lld",res);
    return 0;
}