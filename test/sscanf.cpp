#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sscanf() 会从 buffer 里读进数据，依照 format 的格式将数据写入到 argument 里，注意这里的 argument 需要使用地址符号
    // format 格式参考 scanf() 的输入格式即可

    // 1、取需要的字符串
    int year,month,day;
    sscanf("2022.09.21","%d.%d.%d",&year,&month,&day);// 提取年、月、日
    printf("%d %d %d\n",year,month,day);


    //2、 %ns 提取长度为 n 的字符串
    char str1[10];
    sscanf("20220901000","%8s",str1);// 提取长度为 8 的字符串
    printf("%s\n",str1);


    // 3、将数字表示的字符串转换为整型变量
    int num;
    sscanf("123456","%d",&num);
    printf("%d\n",num);


    // 4、取到指定字符为止的字符串
    char str2[10];
    sscanf("test 01","%[^ ]",str2);// 取遇到空格为止的字符串
    puts(str2);
    char str3[10];
    sscanf("test/01","%[^/]",str3);// 取遇到'/'为止的字符串
    puts(str3);


    // 5、取仅包含指定字符集的字符串
    char str4[20];
    sscanf("123456testSIX","%[1-9a-z]",str4);// 只取数字和小写字母
    puts(str4);


    // 6、跳过不想要的数据
    char str5[20];
    // %s 读取时是以空格和换行作为结束标志的！
    sscanf("test TEST","%*s%s",str5);// 使用 %*s 来跳过前一个字符串
    puts(str5);


    // 给定一个字符串test/unique_11@qq.com，获取 / 和 @ 之间的字符串
    char str6[20];
    sscanf("test/unique_11@qq.com","%*[^/]/%[^@]",str6);// 先把 test/ 过滤掉，再将非'@'的一串内容送到 str6 中
    puts(str6);


    char buf[30];
    sscanf("123456abcdedfBCDEF","%[1-9A-Z]",buf);// 遇到不是1-9或者A-Z的字符时，即遇到小写字母时，就已经结束
    printf("%s\n",buf);
    return 0;
}