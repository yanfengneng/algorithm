#include <iostream>
using namespace std;

const int N = 110;
int v[N],w[N],s[N];
int f[N][N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    
    // ���ذ���ر���
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=s[i]&&k*v[i]<=j;++k) 
                // k=0ʱΪf[i-1][j]��ʾ����ֻ�ÿ���ǰi-1����Ʒ�ļ�ֵ�����ֵ
                // k!=0ʱ��ʾ���ǿ���ǰi����Ʒ�����ǲ�������i����Ʒ������ټ���k����i����Ʒ�����ֵ
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
    
    printf("%d\n",f[n][m]);
    return 0;
}