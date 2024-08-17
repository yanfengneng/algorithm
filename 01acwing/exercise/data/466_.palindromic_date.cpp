#include <bits/stdc++.h>
using namespace std;

int months[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// ���ڻ��Ĵ���˼·һ�㶼�ǿ��ǵ���һ�룬��һ��������ԭ���������ͱ����Ѷȡ�
// ���ڱ��⣬����ֱ��ö����벿�֣�Ȼ���䲹�룬���ɻ������֡�֮���ж�������������Ƿ����������䷶Χ�ڣ��Լ��Ƿ�Ϸ���
bool check(int data)
{
    int year=data/10000,month=data%10000/100,day=data%100;

    // �·ݲ��� [1,12] �µķǷ�������Ϊ 0 �ķǷ���
    if(!month || month> 12 || !day)return false;

    // �Ƕ��µķǷ��������������ڸ��µ��������
    if(month!=2 and day>months[month])return false;

    // ���µ�������Ҫ�����жϣ���Ϊ���漰������ж�
    if(month==2)
    {
        // �����жϣ������ٵ������Ҫ�� 4 ���� year%4==0 and year%100!=0�����ٵ������Ҫ�� 400 ����  year%400==0��
        // �����˳���������������Ϊ�߼������Ǵ������ҽ����жϵģ���ߵĲ������ˣ��ͽ����ж��ұߵ�
        bool leap = year%4==0 and year%100!=0 or year%400==0;
        // ���µ������Ƿ�
        if(day > 28+leap)return false;
    }
    
    // ���зǷ�����ų���Ļ��Ĵ�һ���ǺϷ��Ļ���������
    return true;
}

int main()
{
    int date1,date2;cin>>date1>>date2;
    int res=0;
    // ö����벿��
    for(int i=0;i<10000;i++)
    {
        int x=i,r=i;
        // ����벿��������ԭ�����ɻ��Ĵ�
        for(int j=0;j<4;++j)r=r*10+x%10,x/=10;
        if(r>=date1 and r<=date2 and check(r))res++;
    }
    cout<<res<<endl;
    return 0;
}