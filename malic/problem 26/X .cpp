#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c[10];
        for(int i=0;i<10;i++)cin>>c[i];

        bool flag=true;
        // �� a ����¼��A��ջ��Ԫ�أ��� b ����¼��B��ջ��Ԫ��
        // �����Ԫ��û�� a b ��Ļ�����ʾ�����ɺϷ���������
        int a=-1,b=-1;
        for(int i=0;i<10;++i)
        {
            if(c[i]>a)a=c[i];
            else if(c[i]>b)b=c[i];
            else flag=false;
        }

        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}