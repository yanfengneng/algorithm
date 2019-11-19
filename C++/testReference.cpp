#include <iostream>
using namespace std;

class Base
{
public:
    Base(){cout<<"Base construct..."<<endl;}
    ~Base(){cout<<"Base delete..."<<endl;system("pause");}
};

class Derive:public Base
{
public:
    Derive(){cout<<"Derive construct..."<<endl;}
    ~Derive(){cout<<"Derive delete..."<<endl;system("pause");}
};

bool compare(const string& a,const string& b)
{
    return a>b;
}
int main()
{
    cout<<sizeof(int*)<<endl;
    cout<<sizeof(int)<<endl;
    double a=3.0,&b=a,*c=&a;
    cout<<sizeof(&b)<<" "<<sizeof(double)<<endl;
    cout<<sizeof(c)<<endl;
    system("pause");
}