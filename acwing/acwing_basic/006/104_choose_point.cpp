#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int q[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>q[i];

    sort(q,q+n);
    // ����ѡ����λ����ʱ������֮����С
    int res=0;
    for(int i=0;i<n;++i)res+=abs(q[i]-q[n/2]);
    cout<<res<<endl;
    return 0;
}