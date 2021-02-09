#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool dp[210][210];
/* 
    �ж��ַ��� a b �ܷ񽻴�ƴ�ӳ� c
    ��̬�滮
    ״̬dp[i][j]����ʾ a��ǰi��Ԫ�� �� b��ǰj��Ԫ�� �Ƿ��ܽ������ c��ǰi+j��Ԫ��
    ״̬ת�Ʒ��̣�dp[i][j]=(dp[i-1][j]&&a[i-1]==c[p])||(dp[i][j-1]&&b[j-1]==c[p])
    ע��dp[i][j]�е�i��j��ʾ���ַ���������a[i-1]��ʾa�ĵ�i��Ԫ�أ�ע���±��λ�õĹ�ϵ
    a��ǰi��Ԫ�� �� b��ǰj��Ԫ�� �Ƿ��ܽ������ c��ǰi+j��Ԫ�� 
        1��ȡ���� a[i-1]==c[i+j-1]��a�ĵ�i��Ԫ�غ�c�ĵ�i+j��Ԫ���Ƿ���ȣ��Լ� dp[i-1][j]��a��ǰi-1��Ԫ�� �� b��ǰj��Ԫ���Ƿ���Խ������ c��ǰi-1+j��Ԫ�أ�
        2��ȡ���� b[j-1]==c[i+j-1]��b�ĵ�j��Ԫ�غ�c�ĵ�i+j��Ԫ���Ƿ���ȣ��Լ� dp[i][j-1]��a��ǰi��Ԫ�� �� b��ǰj-1��Ԫ���Ƿ���Խ������ c��ǰi-1+j��Ԫ�أ�
*/
bool check(const string& a,const string& b,const string& c)
{
    memset(dp,0,sizeof dp);
    // ��ʼ��dp[0][0]=1��ʾ aǰ0��Ԫ�� �� b��ǰ0��Ԫ�� �ǿ��Խ������ c��ǰ0+0��Ԫ�ص�
    dp[0][0]=1;
    int n=a.size(),m=b.size();
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
        {
            int p=i+j-1;
            if(i>0)dp[i][j]|=(dp[i-1][j]&&a[i-1]==c[p]);
            if(j>0)dp[i][j]|=(dp[i][j-1]&&b[j-1]==c[p]);
        }
    return dp[n][m];
}

int n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string a,b,c;
        cin>>a>>b>>c;
        if(check(a,b,c))printf("Data set %d: yes\n",i);
        else printf("Data set %d: no\n",i);
    }
    return 0;
}