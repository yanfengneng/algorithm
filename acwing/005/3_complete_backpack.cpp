#include <iostream>
using namespace std;

const int N = 1010;
int v[N],w[N];

int f[N][N];
int dp[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d%d",&v[i],&w[i]);

    // ���ذ��άdp
    /*
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
            for(int k=0;k*v[i]<=j;++k)
                // k=0��ʾf[i-1][j-k*v[i]]+w[i]*k=f[i-1][j]����ʾ����ֻ�ÿ���ǰi-1����Ʒ������ֵ�����ÿ��ǵ�i����Ʒ
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
    */
    
    // �Ż����άdp
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }

    // ��άdp�Ż�Ϊһάdp
    for(int i=1;i<=n;++i)
        for(int j=v[i];j<=m;++j)
            // ����j����С����ö�ٵģ���j-v[i]<j����ô�ض�f[j-v[i]]�ȱ����㣬˵�����������õ��ǵ�i���j-v[i]����f[i][j-v[i]]����������άdp
            // ��01����Ψһ����������j��ö�ٷ���һ����01������j�ɴ�Сö�ٵģ�����ȫ������j��С����ö�ٵ�
            // ��Ϊ01������jҪ�Ǵ�С����ö�ٵģ���ô�����õ���f[i][j-v[i]]��������f[i-1][j-v[i]]��ֻ�ɴ�Сö�٣����ܱ�֤ʹ��f[i-1][j-v[i]]
            // ��Ϊ�����ɱ�֤f[j-v[i]]û�б������������01����Ҫ�Ӵ�Сö��
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    
    printf("%d\n",dp[m]);
    return 0;
}