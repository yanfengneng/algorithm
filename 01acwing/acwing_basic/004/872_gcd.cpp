#include <iostream>
using namespace std;

/*
ŷ�����㷨�����Լ��
    ��b=0ʱ��a��0�����Լ��һ����a
    ��b!=0ʱ��(a,b)�����Լ������(b,a%b)�����Լ������gcd(a,b)=gcd(b,a%b)��֤�����£�
    �蹫Լ��Ϊd��
    1��������ұߣ���d������a��d|a��d������b��d|b����ôa��b������r=a-c*b������cΪ�̣�����dҲ��������(a-c*b)=a%b�ģ�������ұ߳�����
    2���ұ�����ߣ���d������b��d|b��d������a-b*c��d|(a-b*c)����ôdҲ������(a-b*c+b*c) �������b�ı�������������ǿ��������ģ�����ͬ�����õ�d|a���ұ�����߳�����
*/
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}