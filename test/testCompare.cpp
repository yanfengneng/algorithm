#include <iostream>
using namespace std;

int compare(int a,int b)
{
    return (a>b)?1:(a==b)?0:-1;
}
int main()
{
    cout<<compare(1,1)<<endl;
    cout<<compare(1,2)<<endl;
    cout<<compare(1,0)<<endl;
}