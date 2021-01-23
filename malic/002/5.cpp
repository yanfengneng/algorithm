#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int N = 110;
int a[N][N],dp[N][N];

int res=-1;
void dfs(int i,int j,int val)
{
    if(i>n||j>m)return;
    val+=a[i][j];
    if(i==n-1&&j==m-1)res=max(res,val);
    dfs(i+2,j+1,val);
    dfs(i+1,j+2,val);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&a[i][j]);
    memset(dp,-1,sizeof dp);

    dp[0][0]=a[0][0];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            // 剪枝，表示dp[i][j]=-1表明没有经过这个点
            if(dp[i][j]==-1)continue;
            dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]+a[i+1][j+2]);
            dp[i+2][j+1]=max(dp[i+2][j+1],dp[i][j]+a[i+2][j+1]);
        }
    printf("%d",dp[n-1][m-1]);
    return 0;
}