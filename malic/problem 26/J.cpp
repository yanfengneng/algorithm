#include <iostream>
using namespace std;

// m��ƻ������n�����ӵķŷ�
int solve(int m,int n)
{
    // �ݹ���ڣ�0��ƻ��ֻ��1�ַŷ������ƻ��ֻ��1�����ӵĻ���Ҳֻ��1�ַŷ�
    if(m==0||n==1)return 1;
    // ��m<n��������m��ƻ������m�����ӣ�����n�����ӿ϶��п���ģ����m��ƻ������m��������һ����
    if(m<n)return solve(m,m);
    // ��m>=n����Ϊ�����������һ�����п����ӵ��������m��ƻ������n-1���������棬��һ�������ӣ�
    // �ڶ�����û�п����ӣ�ÿ���������ٷ�һ��ƻ������ô����m-n��ƻ����������n��ƻ����
    else return solve(m,n-1)+solve(m-n,n);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        cout<<solve(m,n)<<endl;
    }
    return 0;
}