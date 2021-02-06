#include <iostream>
using namespace std;

const int N =1010;
int a[N],p[N];
int n,x;

int main()
{
    cin>>n>>x;
    x*=100;
    double sum=0;
    for(int i=1;i<=n;++i)cin>>a[i]>>p[i];

    for(int i=1;i<=n;++i)
    {
        sum+=a[i]*p[i];
        if(sum>x){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}