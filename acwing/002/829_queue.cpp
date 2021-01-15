#include <iostream>
#include <string>
using namespace std;

const int N = 1e6+10;
// 定义队列，hh表示队头，tt表示队尾
int q[N],hh=0,tt=-1;

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
            q[++tt]=x;
        }
        else if(op=="pop")
        {
            hh++;
        }
        else if(op=="empty")
        {
            if(hh<=tt)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else
        {
            cout<<q[hh]<<endl;
        }
    }
    return 0;
}