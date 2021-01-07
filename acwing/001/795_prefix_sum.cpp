#include <iostream>

using namespace std;

const int N=1e5+10;

int a[N],s[N];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    // 前缀和的初始化
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    while(m--)
    {
        int  l,r;
        scanf("%d %d",&l,&r);
        // 前 r 个数的和减去前 l-1 个数的和为 [l,r] 的区间和
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}