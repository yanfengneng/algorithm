#include <iostream>
using namespace std;

int n;

int main()
{
    cin>>n;
    int res=0;
    while(n--)
    {
        int x;
        cin>>x;
        res+=x-1;
    }
    cout<<res<<endl;
    return 0;    
}