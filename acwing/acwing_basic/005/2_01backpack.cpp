#include <iostream>
using namespace std;

const int N = 1010;

int n,m;
int V[N],W[N];
int f1[N][N];
int f2[N];

// ��άdp
void dp1()
{
    // ��ʼ����dp
    // ��ʼ��ʱ��f[0][j]=0��ʾǰ0����Ʒѡ�������������j�ļ�ֵΪ0������i��1��ʼѭ��
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            f1[i][j]=f1[i-1][j];
            // �����ұ��Ӽ���һ�����ڣ���Ϊ�ұ߼��ϱ��������i����Ʒ������ֻ�е�ǰ�����j���ڵ���v[i]ʱ������ѡ��i����Ʒ
            if(j>=V[i])f1[i][j]=max(f1[i][j],f1[i-1][j-V[i]]+W[i]);
        }
    cout<<f1[n][m]<<endl;
}


// �Ż����һάdp
void dp2()
{
    for(int i=1;i<=n;++i)
        // �Ӵ�С����ö�٣���֤f[j-v[i]]��û�б����¹�����ʱ��f[j-v[i]]����һ���f[i-1][j-v[i]]
        for(int j=m;j>=V[i];--j)
            f2[j]=max(f2[j],W[i]+f2[j-V[i]]);
    
    cout<<f2[m]<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>V[i]>>W[i];
    
    dp2();
    
    return 0;
}