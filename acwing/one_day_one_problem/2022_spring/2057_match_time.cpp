#include <iostream>
using namespace std;

int d,h,m;

// ����һ��ֱ��������ʱ������ֵ�������������Ƿ������۳����ģ��ܻ���ʱ�䲻����������
int slove1()
{
    if(d==11&&h<11)return -1;
    return (d-11)*1440+(h-11)*60+(m-11);
}

// ��������ֱ�Ӱ�������ʱ��ת��Ϊ������ת��Ϊ����ĳ��ʱ���������ķ�����
// �����10��31��00:00���������ķ���������ʼʱ��Ϊ11��11��11:11������ʱ��Ϊ11��d��h:m
int slove2()
{
    int a=11*1440+11*60+11;
    int b=d*1440+h*60+m;
    if(a>b)return -1;
    else return b-a;
}

int main()
{
    scanf("%d%d%d",&d,&h,&m);
    cout<<slove2()<<endl;
    return 0;
}