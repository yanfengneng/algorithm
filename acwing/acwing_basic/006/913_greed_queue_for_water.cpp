#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,q[N];
using LL = long long;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);

    sort(q,q+n);
    LL res=0;
    for(int i=0;i<n;++i)
        res+=q[i]*(n-1-i);
    cout<<res<<endl;
    return 0;
}