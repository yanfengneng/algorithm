#include <iostream>
using namespace std;

int a[110];

int main()
{
    int x;
    // a[i] ��ʾ�������� i
    while(scanf("%d",&x)&&x!=0)a[x]++;

    int res=0;
    // ��Ϊ��2��15�� 1~99 ������������������ֻ��ö��[1,50]�е�2����
    for(int i=1;i<=50;i++)
        if(a[i]&&a[i*2])res++;

    printf("%d\n",res);
    return 0;
}