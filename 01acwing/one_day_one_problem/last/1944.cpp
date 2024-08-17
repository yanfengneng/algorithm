#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> cnt;

int main()
{
    int n;cin>>n;
    while(n--){
        string s[3];
        for(int i=0;i<3;++i)cin>>s[i];
        // ÅÅĞòºó×ÖµäĞòÎ¨Ò»
        sort(s,s+3);
        cnt[s[0]+" "+s[1]+" "+s[2]]++;
    }
    int res=0;
    for(auto [k,v]:cnt)res=max(res,v);
    cout<<res<<endl;
    return 0;
}