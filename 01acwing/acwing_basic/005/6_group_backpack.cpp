#include <iostream>
using namespace std;

const int N = 110;

int v[N][N],w[N][N],s[N];
int f[N];
int n,m;

int main()
{
    cin>>n>>m;
    
    // i ����ţ�j �����ڱ��
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }

    /*
        ����״̬����
        ��άdp�Ż�Ϊһάdp��
            1�����Ҫ�õ���һ���״̬������i��Ҫ�õ���i-1������ݣ���ôjҪ�Ӵ�С����ö�٣���Ϊ��һ���������û�б��������
            2�����ֻҪ�õ������״̬������i��Ҫ�õ���i������ݣ���ôjֻ��Ҫ��С�������ö�پ����ˣ���Ϊǰ��j-v[i]�Ǳ�������ģ�Ϊ��i������
        ����Ϊ���鱳�����⣬��Ҫ�õ���i-1�����ݣ����j���ɴ�С����ö�ٵ�
    */
    for(int i=1;i<=n;++i)
        for(int j=m;j>=0;--j)
            for(int k=0;k<s[i];++k)// kѡ��i��ĵ�k+1����Ʒ
                if(j>=v[i][k])
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    
    cout<<f[m]<<endl;
    return 0;
}