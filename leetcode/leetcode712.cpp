#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    //题解：动态规划，转换为求1143. 最大公共字串的ASCII码之和
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s1[i-1]==s2[j-1]){
                    //int+char，会发生类型转换，char会转换为10进制数字
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int total=0;
        for(char c:s1)total+=c;
        for(char c:s2)total+=c;
        //最小ASCII删除和=两个字符串的ASCII码之和-最大公共字串的ASCII码之和
        return total-2*dp[m][n];
    }
};

int main()
{
    cout<<Solution().minimumDeleteSum("sea","eat")<<endl;
    system("pause");
}