#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    while(n--)
    {
        int a;cin>>a;
        int res=a;
        // ���¾��Ƿֽ���������ģ���ˣ����ù�ʽ��ŷ������
        for(int i=2;i<=a/i;++i)
        {
            if(a%i==0)// a���Ա�������i���������i�����д�������������
            {
                // ����iΪ��������(1-1/i)�����С������˱���Ϊ(i-1)/i
                res=res/i*(i-1);
                while(a%i==0)a/=i;
            }
        }
        // a�������һ������sqrt(a)�������ӣ����a>1��ʾ��������������ˣ���Ҫ���м���
        if(a>1)res=res/a*(a-1);
        cout<<res<<endl;
    }
    return 0;
}