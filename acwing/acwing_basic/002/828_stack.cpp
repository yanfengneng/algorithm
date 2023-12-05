#include <iostream>
#include <string>
using namespace std;

const int N = 1e5+10;
int stk[N],tt=0;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin>>m;
    while(m--)
    {
        string op;
        int x;
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            stk[++tt]=x;
        }
        else if(op=="pop")
        {
            tt--;
        }
        else if(op=="empty")
        {
            if(tt>0)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else
        {
            cout<<stk[tt]<<endl;
        }
    }
    return 0;
}