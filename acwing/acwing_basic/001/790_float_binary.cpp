#include <iostream>
using namespace std;

int main()
{
    double x;
    scanf("%lf",&x);
    //cin>>x;
    double l=-10000,r=10000;
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid*mid>=x)r=mid;// ����ƽ�
        else l=mid;// ���ұƽ�
    }
    printf("%lf\n",l);
    return 0;
}