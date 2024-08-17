#include <bits/stdc++.h>
using namespace std;

int months[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year,int month,int day)
{
    // 月份不在 [1,12] 月的非法；天数为 0 的非法；
    if(!month || month> 12 || !day)return false;

    // 非二月的非法天数：天数大于该月的最大天数
    if(month!=2 and day>months[month])return false;

    // 二月的天数需要单独判断，因为会涉及闰年的判断
    if(month==2)
    {
        // 闰年判断：非整百的年份需要被 4 整除 year%4==0 and year%100!=0；整百的年份需要被 400 整除  year%400==0；
        // 这里的顺序不能随意调换，因为逻辑运算是从左往右进行判断的，左边的不满足了，就进行判断右边的
        bool leap = year%4==0 and year%100!=0 or year%400==0;
        // 二月的天数非法
        if(day > 28+leap)return false;
    }
    
    // 所有非法情况排除后的回文串一定是合法日期了
    return true;
}

int main()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    // 从小到大进行枚举，这样输入的日期是从小到大排序的
    for(int i=19600101;i<=20591231;i++)
    {
        int year=i/10000,month=i%10000/100,day=i%100;
        if(check(year,month,day))
        {
            if(((year%100)==a and month==b and day==c)or    // 年/月/日
            (month==a and day==b and (year%100)==c) or      // 月/日/年
            (day==a and month==b and (year%100)==c))        // 日/月/年
                printf("%d-%02d-%02d\n",year,month,day);    // 不足两位时在高位补 0
        }
    }
    return 0;
}