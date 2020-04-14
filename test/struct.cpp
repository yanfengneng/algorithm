#include <iostream>
using namespace std;

//window默认对齐字节数为8，test中数据类型最大字节数为8，所以我们按8字节对齐
//最后结构体大小为最大数据类型的整数倍
struct test1{
    int a;//a占0-3，空余4个字节，不属于任何变量
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
   char a;//0，空余1个字节
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