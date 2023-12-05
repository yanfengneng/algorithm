#include <bits/stdc++.h>
using namespace std;

int f1[1010][1010],f2[1010][1010],f3[1010][1010];

class Solution {
public:
    // 求最长回文子序列
    void lps(string &s,int f[][1010])
    {
        int n=s.size();
         // i 反向遍历，j 从 i 行的 i+1 位置从左到右遍历
        for(int i=n;i>0;i--){
            f[i][i]=1;
            for(int j=i+1;j<=n;++j){
                if(s[i]==s[j])f[i][j]=f[i+1][j-1]+2;
                else f[i][j]=max(f[i+1][j],f[i][j-1]);
            }
        }
    }

    // 求最长公共子序列
    void lcs(string& a,string& b,int f[][1010])
    {
        int n=a.size(),m=b.size();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(a[i]==b[j])f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
    }

    int longestPalindrome(string a, string b) {
        int n=a.size(),m=b.size();
        reverse(b.begin(),b.end());
        memset(f1,0,sizeof f1),memset(f2,0,sizeof f2),memset(f3,0,sizeof f3);
        
        a=' '+a,b=' '+b;
        lcs(a,b,f1),lps(a,f2),lps(b,f3);

        int res=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(f1[i][j])
                    res=max(res,f1[i][j]*2+max(f2[i+1][n],f3[j+1][m]));
        return res;
    }
};

int main()
{
    string a="cacb",b="cbba";
    cout<<Solution().longestPalindrome(a,b)<<endl;
    return 0;
}