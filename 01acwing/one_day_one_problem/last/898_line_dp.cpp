#include <iostream>
using namespace std;

const int N = 510;
int f[N][N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            scanf("%d",&f[i][j]);
    
    for(int i=n-1;i>0;--i)
        for(int j=1;j<=i;++j)
            f[i][j]+=max(f[i+1][j],f[i+1][j+1]);
    
    cout<<f[1][1]<<endl;

    return 0;
}