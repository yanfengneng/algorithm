#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string s) {
        for(int l=0,r=0;r<s.size();l=++r){
            while(r<s.size()&&s[r]!=' ')r++;
            for(int i=l;i<r;++i)s[l]=tolower(s[l]);
            cout<<l<<" "<<r<<endl;
            if(r-l>2)s[l]=toupper(s[l]);
        }
        return s;
    }
};

int main()
{
    cout<<Solution().capitalizeTitle("capiTalIze tHe titLe")<<endl;
    return 0;
}