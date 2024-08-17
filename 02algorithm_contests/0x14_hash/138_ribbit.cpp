#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 1e6+10;
char s[N];
// f用来存放hash值的，p用来表示p进制的
unsigned long long f[N],p[N];

int main()
{
    //string s;
    //cin>>s;
    //int n=s.size();
    scanf("%s",s);
    int n=strlen(s);
    p[0]=1;// 131^0=1
    for(int i=1;i<=n;++i)
    {
        f[i]=f[i-1]*131+(s[i-1]-'a'+1);// 计算1-n的hash值
        p[i]=p[i-1]*131;// 131^i
    }
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(f[r1]-f[l1-1]*p[r1-l1+1]==f[r2]-f[l2-1]*p[r2-l2+1])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}