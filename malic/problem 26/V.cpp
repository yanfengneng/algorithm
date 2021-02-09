#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool dp[210][210];
/* 
    判断字符串 a b 能否交错拼接成 c
    动态规划
    状态dp[i][j]：表示 a的前i个元素 和 b的前j个元素 是否能交错组成 c的前i+j个元素
    状态转移方程：dp[i][j]=(dp[i-1][j]&&a[i-1]==c[p])||(dp[i][j-1]&&b[j-1]==c[p])
    注意dp[i][j]中的i和j表示的字符个数，而a[i-1]表示a的第i个元素，注意下标和位置的关系
    a的前i个元素 和 b的前j个元素 是否能交错组成 c的前i+j个元素 
        1）取决于 a[i-1]==c[i+j-1]（a的第i个元素和c的第i+j个元素是否相等）以及 dp[i-1][j]（a的前i-1个元素 和 b的前j个元素是否可以交错组成 c的前i-1+j个元素）
        2）取决于 b[j-1]==c[i+j-1]（b的第j个元素和c的第i+j个元素是否相等）以及 dp[i][j-1]（a的前i个元素 和 b的前j-1个元素是否可以交错组成 c的前i-1+j个元素）
*/
bool check(const string& a,const string& b,const string& c)
{
    memset(dp,0,sizeof dp);
    // 初始化dp[0][0]=1表示 a前0个元素 和 b的前0个元素 是可以交错组成 c的前0+0个元素的
    dp[0][0]=1;
    int n=a.size(),m=b.size();
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            int p=i+j-1;
            if(i>0)dp[i][j]|=(dp[i-1][j]&&a[i-1]==c[p]);
            if(j>0)dp[i][j]|=(dp[i][j-1]&&b[j-1]==c[p]);
        }
    return dp[n][m];
}

int n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string a,b,c;
        cin>>a>>b>>c;
        if(check(a,b,c))printf("Data set %d: yes\n",i);
        else printf("Data set %d: no\n",i);
    }
    return 0;
}