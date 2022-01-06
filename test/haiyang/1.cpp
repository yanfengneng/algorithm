#include <iostream>
#include <semaphore.h>
using namespace std;

int a[35];

int main()
{
    int x,n=0;
    while(cin>>x)
    {
        if(x==0)break;
        a[n++]=x;
    }
    int i=0;
    int res=0;
    while(i<n)
    {
        if(a[i]==1)res++,i++;
        else {
            int j=i;
            while(i<n&&a[i]==2){
                res+=(i-j+1)*2;
                i++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}