#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char s[N],t[N];
int f[N][N];// ״̬f[i][j]��ʾs[1...i]��t[1...j]����������еĳ���
int n,m;

int main()
{
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    memset(f,0,sizeof f);
    // ��������ı���˳����״̬ת�Ʒ��̿�֪�ɾ������һ�к�ͬ����ߵó������ֻ���С����ö�ټ���
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            // ��Ⱦͽ�������������г���+1
            if(s[i]==t[j])f[i][j]=f[i-1][j-1]+1;
            // ����Ⱦ�ȡǰ��������������s[i]��t[j]��������г��ȵ����ֵ
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout<<f[n][m]<<endl;
    return 0;
}