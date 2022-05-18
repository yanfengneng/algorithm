#include <iostream>
using namespace std;

int d,h,m;

// 方法一：直接用两个时间做差值，但是这样做是分类讨论出来的，很花费时间不建议这样做
int slove1()
{
    if(d==11&&h<11)return -1;
    return (d-11)*1440+(h-11)*60+(m-11);
}

// 方法二：直接把这两个时间转换为整数，转换为距离某个时间所经过的分钟数
// 如距离10月31日00:00的所经过的分钟数，起始时间为11月11日11:11，结束时间为11月d日h:m
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