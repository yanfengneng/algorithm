#include <iostream>
using namespace std;

const int N = 110;

int v[N][N],w[N][N],s[N];
int f[N];
int n,m;

int main()
{
    cin>>n>>m;
    
    // i 是组号，j 是组内编号
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }

    /*
        进行状态计算
        二维dp优化为一维dp：
            1）如果要用到上一层的状态，即第i层要用到第i-1层的数据，那么j要从大到小进行枚举，因为上一层的数据是没有被计算过的
            2）如果只要用到本层的状态，即第i层要用到第i层的数据，那么j只需要由小到大进行枚举就行了，因为前面j-v[i]是被计算过的，为第i层数据
        本题为分组背包问题，需要用到第i-1层数据，因此j是由大到小进行枚举的
    */
    for(int i=1;i<=n;++i)
        for(int j=m;j>=0;--j)
            for(int k=0;k<s[i];++k)// k选第i组的第k+1个物品
                if(j>=v[i][k])
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    
    cout<<f[m]<<endl;
    return 0;
}