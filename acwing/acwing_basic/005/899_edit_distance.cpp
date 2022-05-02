#include <bits/stdc++.h>
using namespace std;

const int N = 15,M = 1010;
int f[N][N];
char str[M][N];
int n,m;

int edit_distance(char* a,char *b)
{
    // �����ַ���a b���±�1��ʼ�ĳ���
    int la=strlen(a+1),lb=strlen(b+1);
    // ��ʼ��f[i][0]����ʾ���a��ǰi���ַ���b��ǰ0���ַ���ƥ�䣬ֻ����ɾ�������ˣ�ɾ��������a�ĳ������
    for(int i=0;i<=la;++i)f[i][0]=i;
    // ��ʼ��f[0][j]����ʾ���a��ǰ0���ַ���b��ǰj���ַ���ƥ�䣬ֻ������Ӳ����ˣ���Ӵ�����b�ĳ������
    for(int j=0;j<=lb;++j)f[0][j]=j;
    // ��ʼ����״̬ת��
    for(int i=1;i<=la;++i)
        for(int j=1;j<=lb;++j)
        {
            // ɾ��a[i]�����b[j]
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            // �޸�a[i]Ϊb[j]��񣬲���Ⱦ��޸�һ�Σ���ȾͲ���Ҫ�޸�
            f[i][j]=min(f[i][j],f[i-1][j-1]+(a[i]!=b[j]));
        }
    return f[la][lb];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",str[i]+1);// ���±�1��ʼ����

    while(m--)
    {
        char s[N];int limit;
        scanf("%s%d",s+1,&limit);
        int cnt=0;
        // ���㵱ǰ������ַ�����n���ַ����ı༭����С�ڵ���limit���ַ�������
        for(int i=0;i<n;++i)
            if(edit_distance(str[i],s)<=limit)cnt++;
        cout<<cnt<<endl;
    }

    return 0;
}