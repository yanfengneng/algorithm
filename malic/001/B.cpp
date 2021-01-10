#include <iostream>
using namespace std;

int count[10];
int a[1000010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<n;++i)count[a[i]]++;
    if(count[1]!=0&&count[2]!=0)cout<<"0"<<endl;
    else if(count[3]!=0&&count[4]!=0)cout<<"0"<<endl;
    else if((count[5]!=0&&count[6]==0)||(count[5]==0&&count[6]!=0))cout<<"0"<<endl;
    else if(count[7]==0&&count[8]==0)cout<<"0"<<endl;
    else cout<<"1"<<endl;
    return 0;
}