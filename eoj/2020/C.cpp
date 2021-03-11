#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,n;
    scanf("%d %d",&d,&n);
    double time=0.0;
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        time=max(time,1.0*(d-a)/b);
    }
    printf("%.6f\n",1.0*d/time);
    return 0;
}