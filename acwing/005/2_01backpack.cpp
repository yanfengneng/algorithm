#include <iostream>
using namespace std;

const int N = 1010;
int v[N],w[N];
int f[N][N];
// dp��ʾ�Ż�Ϊһά����
int dp[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i];

    // ����f[0][0~m]Ϊ0����Ʒ���ܲ���������ֵΪ0��ȫ�ֱ�����ʼ��Ϊ0�ˣ��Ͳ��ù���
    // ����i��1��ʼѭ��
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            // �ұ����������i���������������j������ֵ������������һ�����ڵ�
            // ���ұ������һ�����ڣ�����Ϊ�ռ�������j<viʱ��Ҳ����װ����viʱ��Ϊ�ռ�
            // ������ң�����ִ������������ִ���ұ����
            f[i][j]=f[i-1][j];
            if(j>=v[i])f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    
    // ��άdp��ά��һάdp
    for(int i=1;i<=n;++i)
        for(int j=m;j>=v[i];--j)
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);

    cout<<dp[m]<<endl;
    return 0;
}