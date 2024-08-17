#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int a[N],n;

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    int average=accumulate(a,a+n,0)/n;
    int res=0;
    for(int i=0;i<n;++i)
        if(a[i]<average)res+=average-a[i];
    cout<<res<<endl;
    return 0;
}