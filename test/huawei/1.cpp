#include <bits/stdc++.h>
using namespace std;
using LL = long long;

string s;
int cnt[26]={0};

LL helper(int n){
    LL res=1;
    for(int i=1;i<=n;++i)res*=i;
    return res;
}
int main()
{
    cin>>s;
    int n=s.size();
    memset(cnt,0,sizeof cnt);
    LL res=helper(n);
    for(char c:s){
        cnt[c-'A']++;
    }
    for(int i=0;i<26;++i){
        if(cnt[i])res/=helper(cnt[i]);
    }
    cout<<res<<endl;
    return 0;
}