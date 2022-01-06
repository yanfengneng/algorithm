#include <iostream>
using namespace std;

bool isOK(int y)
{
    if(y%4==0&&y%100!=0)return true;
    if(y%400==0)return true;
    return false;
}

int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int y,d;
    cin>>y>>d;
    int m=0,data=0;
    for(int i=1;i<=12;i++)
    {
        if(i!=2)
        {
            if(d>a[i])d-=a[i];
            else {data=d;m=i;break;}
        }
        else
        {
            if(isOK(y))
            {
                if(d>29)d-=29;
                else {data=d;m=i;break;}
            }
            else
            {
                if(d>28)d-=28;
                else {data=d;m=i;break;}
            } 
        }
    }
    cout<<m<<"\n"<<data<<endl;
    return 0;
}