#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sscanf() ��� buffer ��������ݣ����� format �ĸ�ʽ������д�뵽 argument �ע������� argument ��Ҫʹ�õ�ַ����
    // format ��ʽ�ο� scanf() �������ʽ����

    // 1��ȡ��Ҫ���ַ���
    int year,month,day;
    sscanf("2022.09.21","%d.%d.%d",&year,&month,&day);// ��ȡ�ꡢ�¡���
    printf("%d %d %d\n",year,month,day);


    //2�� %ns ��ȡ����Ϊ n ���ַ���
    char str1[10];
    sscanf("20220901000","%8s",str1);// ��ȡ����Ϊ 8 ���ַ���
    printf("%s\n",str1);


    // 3�������ֱ�ʾ���ַ���ת��Ϊ���ͱ���
    int num;
    sscanf("123456","%d",&num);
    printf("%d\n",num);


    // 4��ȡ��ָ���ַ�Ϊֹ���ַ���
    char str2[10];
    sscanf("test 01","%[^ ]",str2);// ȡ�����ո�Ϊֹ���ַ���
    puts(str2);
    char str3[10];
    sscanf("test/01","%[^/]",str3);// ȡ����'/'Ϊֹ���ַ���
    puts(str3);


    // 5��ȡ������ָ���ַ������ַ���
    char str4[20];
    sscanf("123456testSIX","%[1-9a-z]",str4);// ֻȡ���ֺ�Сд��ĸ
    puts(str4);


    // 6����������Ҫ������
    char str5[20];
    // %s ��ȡʱ���Կո�ͻ�����Ϊ������־�ģ�
    sscanf("test TEST","%*s%s",str5);// ʹ�� %*s ������ǰһ���ַ���
    puts(str5);


    // ����һ���ַ���test/unique_11@qq.com����ȡ / �� @ ֮����ַ���
    char str6[20];
    sscanf("test/unique_11@qq.com","%*[^/]/%[^@]",str6);// �Ȱ� test/ ���˵����ٽ���'@'��һ�������͵� str6 ��
    puts(str6);


    char buf[30];
    sscanf("123456abcdedfBCDEF","%[1-9A-Z]",buf);// ��������1-9����A-Z���ַ�ʱ��������Сд��ĸʱ�����Ѿ�����
    printf("%s\n",buf);
    return 0;
}