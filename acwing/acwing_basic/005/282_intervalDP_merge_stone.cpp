#include <bits/stdc++.h>
using namespace std;

const int N = 310;

// 定义数据数组，前缀和数组，状态数组
int a[N],pre[N];
// f[i][j]表示区间[i,j]合并的最小值
int f[N][N];

int main()
{
    int n;cin>>n;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i][i]=0;
        pre[i]=pre[i-1]+a[i];// 前缀和
    }
    // 区间dp：先枚举区间长度，再枚举区间左端点
    for(int len=2;len<=n;++len)
        for(int l=1;l+len-1<=n;++l)// 所有区间长度为len的左端点，左端点的最大值为n-len+1，位置=长度-1
        {
            int r=l+len-1;// 右端点为左端点+len-1，减1是减去左端点所占的点
            // 枚举将[l,r]划分为两个子集所有的点k，f[l][k]+f[k+1][r]再加上合并区间[l,r]的代价
            for(int k=l;k<r;++k)
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+pre[r]-pre[l-1]);
        }
    
    cout<<f[1][n]<<endl;
    return 0;
}