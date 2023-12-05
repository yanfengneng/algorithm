#include <iostream>
using namespace std;

const int N = 1e5+10;
char s[N];
unsigned long long f[N],p[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    p[0]=1;// 131^0=1

    // 预处理前缀和
    for(int i=1;i<=n;++i)
    {
        f[i]=f[i-1]*131+s[i-1];
        p[i]=p[i-1]*131;// 131^i
    }

    // m次区间查询
    while(m--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(f[r1]-f[l1-1]*p[r1-l1+1]==f[r2]-f[l2-1]*p[r2-l2+1])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}