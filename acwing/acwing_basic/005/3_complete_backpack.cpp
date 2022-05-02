#include <iostream>
using namespace std;

const int N = 1010;
int n,m;
int v[N],w[N];
int f1[N][N];
int f2[N];

// 二维dp：对于体积的顺序没有限制，想怎么循环就怎么循环，没有任何限制
void dp1()
{
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            // 不选物品i且总体积不超过j
            f1[i][j]=f1[i-1][j];
            // f[i][j-v[i]]=max(f[i-1][j-k*v[i]])，其中k大于等于1；所以只用f[i][j-v[i]]+w就可以推出f[i][j]的所有右子集了
            if(j>=v[i])f1[i][j]=max(f1[i][j],f1[i][j-v[i]]+w[i]);
        }
        
    cout<<f1[n][m]<<endl;
}

// 优化后的一维dp：由小到大的枚举体积就行，这样可以保证较小值j-v[i]以被计算出来，是第i层的f[i][j-v[i]]
void dp2()
{
    for(int i=1;i<=n;++i)
        for(int j=v[i];j<=m;++j){
            // 由于此时的f2[j]还未被更新，所以此时用的就是上一层的f2[i-1][j]，这个等式恒成立；
            // f2[i][j]=f2[i-1][j]  ==>>  f2[j]=f2[j]
            // j-v[i]<=j，所以由小到大枚举j时，较小值j-v[i]已经被先计算出来了，此时的f[j-v[i]]就是第i层的f[i][j-v[i]]
            f2[j]=max(f2[j],f2[j-v[i]]+w[i]);
        }
    cout<<f2[m]<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];
    dp2();
    return 0;
}