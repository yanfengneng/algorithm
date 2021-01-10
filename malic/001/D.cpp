#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int> a(N,0);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    sort(a.begin(),a.begin()+n);

    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        int j;
        for(j=0;j<i;++j)
        {
            if(a[i]%a[j]==0)break;
        }
       
    }
    cout<<res<<endl;
    return 0;
}