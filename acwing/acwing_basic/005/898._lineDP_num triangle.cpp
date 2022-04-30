#include <bits/stdc++.h>
using namespace std;

const int N = 510,INF = 1e9;
int a[N][N],f1[N][N],f2[N][N];
int n;

// �Զ����½���dp
void dp1()
{
    // �����iҪ��1��ʼ��ʼ������Ϊ����ڶ�������ʱ�����õ���һ�е��е�f[1][0]��f[1][2]����Ȼj�ĳ�ʼ��Ҫ��[0,i+1]�ˣ���Ϊ��һ���еĵ�0�к͵�i�е�״̬��Ҫ���õ������Գ�ʼ��Ϊ������
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i+1;++j)
            f1[i][j]=-INF;
    f1[1][1]=a[1][1];

    // ��ʼ����״̬ת��
    for(int i=2;i<=n;++i)
        for(int j=1;j<=i;++j)
            f1[i][j]=max(f1[i-1][j-1],f1[i-1][j])+a[i][j];

    // �����һ����Ѱ��·�����ֵ
    int res=-INF;
    for(int i=1;i<=n;++i)res=max(res,f1[n][i]);
    cout<<res<<endl;
}

int main()
{
    cin>>n;
    // ��ʹ���Զ����½���dpʱ����Ҫʹ��f[i-1]����״̬�������±��1��ʼ����
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cin>>a[i][j];
    dp1();
    return 0;
}