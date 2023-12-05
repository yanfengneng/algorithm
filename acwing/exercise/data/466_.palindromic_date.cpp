#include <bits/stdc++.h>
using namespace std;

int months[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 对于回文串的思路一般都是考虑单独一半，另一半做镜像还原这样来降低编码难度。
// 对于本题，我们直接枚举左半部分，然后将其补齐，构成回文数字。之后判断这个回文数字是否在输入区间范围内，以及是否合法。
bool check(int data)
{
    int year=data/10000,month=data%10000/100,day=data%100;

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
    
    // 所有非法情况排除后的回文串一定是合法的回文日期了
    return true;
}

int main()
{
    int date1,date2;cin>>date1>>date2;
    int res=0;
    // 枚举左半部分
    for(int i=0;i<10000;i++)
    {
        int x=i,r=i;
        // 对左半部分做镜像还原，构成回文串
        for(int j=0;j<4;++j)r=r*10+x%10,x/=10;
        if(r>=date1 and r<=date2 and check(r))res++;
    }
    cout<<res<<endl;
    return 0;
}