#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidWords(string s) {
        int res=0,i=0,n=s.size();
        while(i<n){
            string a;
            while(i<n&&s[i]!=' ')a+=s[i++];
            if(check(a)){
                cout<<a<<' ';
                res++;
            }
            while(i<n&&s[i]==' ')i++;
        }
        return res;
    }

    bool check(string a){
        if(a.empty())return 0;
        int cnt=0,n=a.size();
        for(int i=0;i<n;++i){
            if(a[i]>='0'&&a[i]<='9')return false;
            if((i==0||i==n-1)&&a[i]=='-')return false;
            if(i!=n-1&&(a[i]=='!'||a[i]=='.'||a[i]==','))return false;
            if(a[i]=='-'){
                cnt++;
                if(cnt>1)return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution().countValidWords(" o6 t");
}