#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e5;
int f[N],f2[N][N];
class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        return dp2(a);
    }

    // 从下到上进行状态转移
    int dp1(vector<vector<int>>& a)
    {
        int n=a.size();
        memset(f,0,sizeof f);
        // 初始化最后一行的状态
        for(int i=0;i<a.back().size();++i)f[i]=a[n-1][i];
        // 从倒数第二行开始进行状态转移
        /*for(int i=n-2;i>=0;i--)
            for(int j=0;j<=i;++j)
                 f[i][j]=min(f[i+1][j],f[i+1][j+1])+a[i][j];
        */
        // 也可以进行空间优化，由于i是从大到小进行枚举的，所以状态转移中的f[j],f[j+1]是第i+1中的数据
        // j由于也是从小到大进行枚举的，所以j+1也是第i+1行中的数据
        for(int i=n-2;i>=0;--i)
            for(int j=0;j<=i;++j)
                f[j]=min(f[j],f[j+1])+a[i][j];
        return f[0];
    }

    // 从上到下进行状态转移
    int dp2(vector<vector<int>>& a)
    {
        int n=a.size();
        memset(f2,0x3f,sizeof f2);
        f2[0][0]=a[0][0];
        for(int i=1;i<n;++i)
            for(int j=0;j<=i;++j)
                // 边界情况特殊处理
                if(j==0)f2[i][j]=f2[i-1][j]+a[i][j];
                else if(j==i)f2[i][j]=f2[i-1][j-1]+a[i][j];
                else f2[i][j]=min(f2[i-1][j],f2[i-1][j-1])+a[i][j];
        
        int res=INF;
        for(int i=0;i<n;++i)res=min(res,f2[n-1][i]);
        return res;
    }
};

int main()
{
    vector<vector<int>> t={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumTotal(t)<<endl;
    return 0;
}