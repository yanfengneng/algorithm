#include <bits/stdc++.h>
using namespace std;

const int N = 310;

// �����������飬ǰ׺�����飬״̬����
int a[N],pre[N];
// f[i][j]��ʾ����[i,j]�ϲ�����Сֵ
int f[N][N];

int main()
{
    int n;cin>>n;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i][i]=0;
        pre[i]=pre[i-1]+a[i];// ǰ׺��
    }
    // ����dp����ö�����䳤�ȣ���ö��������˵�
    for(int len=2;len<=n;++len)
        for(int l=1;l+len-1<=n;++l)// �������䳤��Ϊlen����˵㣬��˵�����ֵΪn-len+1��λ��=����-1
        {
            int r=l+len-1;// �Ҷ˵�Ϊ��˵�+len-1����1�Ǽ�ȥ��˵���ռ�ĵ�
            // ö�ٽ�[l,r]����Ϊ�����Ӽ����еĵ�k��f[l][k]+f[k+1][r]�ټ��Ϻϲ�����[l,r]�Ĵ���
            for(int k=l;k<r;++k)
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+pre[r]-pre[l-1]);
        }
    
    cout<<f[1][n]<<endl;
    return 0;
}