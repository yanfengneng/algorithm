#include <bits/stdc++.h>
using namespace std;

bool v[25];
class Solution {
public:
    int res=0;
    int maxLength(vector<string>& a) {
        int n=a.size();
        memset(v,0,sizeof v);
        backtrack(a,"",0,n);
        return res;
    }
    
    void backtrack(vector<string>& a,string s,int pos,int n){
        
    }

    bool vaild(const string& s)
    {
        if(s.empty())return true;
        int cnt[26];
        memset(cnt,0,sizeof cnt);
        for(char c:s)cnt[c-'a']++;
        for(int i=0;i<26;++i)
            if(cnt[i]>1)return false;
        return true;
    }
};

int main()
{
    int a=-12;
    cout<<to_string(a)<<endl;
    return 0;
}