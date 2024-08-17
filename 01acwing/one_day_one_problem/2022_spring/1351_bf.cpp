#include <bits/stdc++.h>
using namespace std;

int n;

bool check(vector<int> a,vector<int> b)
{
    for(int i=0;i<3;++i)
    {
        int d=a[i]>=b[i]?a[i]-b[i]:b[i]-a[i];
        int c=min(d,n-d);
        if(c>2)return false;
    }
    return true;
}

// 思路：直接暴力枚举所有的密码，然后判断枚举的密码是否与题目给的两个密码匹配，时间复杂度为1e6可以过
int main()
{
    cin>>n;
    vector<vector<int>> q;
    for(int i=0;i<2;i++){
        int a,b,c;cin>>a>>b>>c;
        q.push_back({a,b,c});
    }

    int res=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(check(q[0],{i,j,k})||check(q[1],{i,j,k}))
                    res++;
    cout<<res<<endl;
    return 0;
}