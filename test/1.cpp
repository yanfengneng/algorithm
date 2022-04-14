#include <iostream>
using namespace std;

struct s1{
    int a;//0-3
    char b;//4
    int c;//8-11
    double d;//16-23
};

int main()
{
    cout<<sizeof(s1)<<endl;
    return 0;
}