#include <iostream>
using namespace std;

//windowĬ�϶����ֽ���Ϊ8��test��������������ֽ���Ϊ8���������ǰ�8�ֽڶ���
//���ṹ���СΪ����������͵�������
struct test1{
    int a;//aռ0-3������4���ֽڣ��������κα���
    double b;//8-15
    char c;//16
};

struct test2{
    double a;//0-7
    int b;//8-11
    char c;//12
    char d;//13
};

struct test3
{
   char a;//0������1���ֽ�
   short b;//2-3
   int c;//4-7
   double d;//8-15
};

int main()
{
    cout<<sizeof(test1)<<endl;
    cout<<offsetof(struct test1,a)<<" "<<offsetof(struct test1,b)<<" "<<offsetof(struct test1,c)<<endl;
    cout<<sizeof(test2)<<endl;
    cout<<offsetof(struct test2,a)<<" "<<offsetof(struct test2,b)<<" "<<offsetof(struct test2,c)<<" "<<offsetof(test2,d)<<endl;
    cout<<sizeof(test3)<<endl;
    cout<<offsetof(struct test3,a)<<" "<<offsetof(struct test3,b)<<" "<<offsetof(struct test3,c)<<" "<<offsetof(test3,d)<<endl;
}