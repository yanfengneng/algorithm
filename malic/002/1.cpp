#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int res=0;
    while(n)
    {
        res++;
        n&=n-1;
    }
    printf("%d",res);
    return 0;
}