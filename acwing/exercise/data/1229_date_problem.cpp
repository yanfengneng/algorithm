#include <bits/stdc++.h>
using namespace std;

int months[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year,int month,int day)
{
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
    
    // ���зǷ�����ų���Ļ��Ĵ�һ���ǺϷ�������
    return true;
}

int main()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    // ��С�������ö�٣���������������Ǵ�С���������
    for(int i=19600101;i<=20591231;i++)
    {
        int year=i/10000,month=i%10000/100,day=i%100;
        if(check(year,month,day))
        {
            if(((year%100)==a and month==b and day==c)or    // ��/��/��
            (month==a and day==b and (year%100)==c) or      // ��/��/��
            (day==a and month==b and (year%100)==c))        // ��/��/��
                printf("%d-%02d-%02d\n",year,month,day);    // ������λʱ�ڸ�λ�� 0
        }
    }
    return 0;
}