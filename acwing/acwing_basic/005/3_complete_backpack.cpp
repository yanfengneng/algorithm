#include <iostream>
using namespace std;

const int N = 1010;
int n,m;
int v[N],w[N];
int f1[N][N];
int f2[N];

// ��άdp�����������˳��û�����ƣ�����ôѭ������ôѭ����û���κ�����
void dp1()
{
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            // ��ѡ��Ʒi�������������j
            f1[i][j]=f1[i-1][j];
            // f[i][j-v[i]]=max(f[i-1][j-k*v[i]])������k���ڵ���1������ֻ��f[i][j-v[i]]+w�Ϳ����Ƴ�f[i][j]���������Ӽ���
            if(j>=v[i])f1[i][j]=max(f1[i][j],f1[i][j-v[i]]+w[i]);
        }
        
    cout<<f1[n][m]<<endl;
}

// �Ż����һάdp����С�����ö��������У��������Ա�֤��Сֵj-v[i]�Ա�����������ǵ�i���f[i][j-v[i]]
void dp2()
{
    for(int i=1;i<=n;++i)
        for(int j=v[i];j<=m;++j){
            // ���ڴ�ʱ��f2[j]��δ�����£����Դ�ʱ�õľ�����һ���f2[i-1][j]�������ʽ�������
            // f2[i][j]=f2[i-1][j]  ==>>  f2[j]=f2[j]
            // j-v[i]<=j��������С����ö��jʱ����Сֵj-v[i]�Ѿ����ȼ�������ˣ���ʱ��f[j-v[i]]���ǵ�i���f[i][j-v[i]]
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