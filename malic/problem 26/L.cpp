#include <iostream>
using namespace std;

int solve(int x,int y,int z)
{
    if(x==0&&y&&z==0)return 0;
    if(x&&y==0&&z==0)return 0;

    if(x+z<y)return (x+z)*2;
    else return y*2+(z-(y-x))/2*2;
}

int main()
{
    int x,y,z;
    cin>>x>>y>>z;

    if(x<y)cout<<solve(x,y,z)<<endl;
    else if(x>y)cout<<solve(y,x,z)<<endl;
    else cout<<(x+y+z/2*2)<<endl;

    return 0;
}