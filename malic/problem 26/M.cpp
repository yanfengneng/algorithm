#include <iostream>
using namespace std;

int a[1010];

int main()
{
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;++i)scanf("%d",&a[i]);

        for(int i=1;i<m;++i)
        {
            if(a[i]+1!=a[i+1])
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }

    return 0;
}