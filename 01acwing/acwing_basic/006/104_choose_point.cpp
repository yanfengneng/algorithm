#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int q[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>q[i];

    sort(q,q+n);
    // 货仓选在中位数上时，距离之和最小
    int res=0;
    for(int i=0;i<n;++i)res+=abs(q[i]-q[n/2]);
    cout<<res<<endl;
    return 0;
}