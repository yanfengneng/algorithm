#include <bits/stdc++.h>
using namespace std;

int n;
int x,y,z;

bool check(int A,int B,int C)
{   
    for(int i=-100;i<100;i++)
        for(int j=-100;j<100;j++)
            for(int k=-100;k<100;k++)
                if(i!=j&&i!=k&&j!=k&&i+j+k==A&&i*j*k==B&&(i*i+j*j+k*k)==C)
                {
                    x=i,y=j,z=k;
                    return true;
                }
    return false;
}

int main()
{
    cin>>n;
    while(n--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        if(check(A,B,C))
        {
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        else cout<<"No solution."<<endl;
    }
    return 0;
}