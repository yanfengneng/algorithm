#include <iostream>
using namespace std;

void divide(int n)
{
    for(int i=2;i<=n/i;++i)
        // ��ö�ٵ�i��ʱ�򣬾ͱ������ǰ�2~i-1֮������������ӳ��ɾ���
        // �����iһ��Ϊ�����ӣ���n�����i���ɾ�
        if(n%i==0)
        {
            int s=0;
            // ͳ��i������
            while(n%i==0)
            {
                s++;
                n/=i;
            }
            printf("%d %d\n",i,s);
        }
    // n�����ֻ�����һ������sqrt(n)�������ӣ�������������sqrt(n)�������ӣ���ô����֮�������n��ì��
    // һ��ĳ������n��Ϊ1�ģ���Ϊ1�Ȳ��Ǻ���Ҳ���������������n>1����ʾ�����Ǹ�����sqrt(n)����������
    if(n>1)printf("%d %d\n",n,1);
    puts("");
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        divide(x);
    }
    return 0;
}