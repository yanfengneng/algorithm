#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char s[N],t[N];
int f[N][N];// 状态f[i][j]表示s[1...i]与t[1...j]最长公共子序列的长度
int n,m;

int main()
{
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    memset(f,0,sizeof f);
    // 至于这里的遍历顺序，用状态转移方程可知由矩阵的上一行和同行左边得出，因此只需从小到大枚举即可
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            // 相等就进行最长公共子序列长度+1
            if(s[i]==t[j])f[i][j]=f[i-1][j-1]+1;
            // 不相等就取前面两个单独不含s[i]和t[j]的最长子序列长度的最大值
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout<<f[n][m]<<endl;
    return 0;
}