#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e5+10;
char str[N][15];

int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s",str[i]);
    // 统计 A C H M R 开头的字符串个数
    int a[5];
    memset(a,0,sizeof a);
    for(int i=0;i<n;++i)
    {
        if(str[i][0]=='A')a[0]++;
        else if(str[i][0]=='C')a[1]++;
        else if(str[i][0]=='H')a[2]++;
        else if(str[i][0]=='M')a[3]++;
        else if(str[i][0]=='R')a[4]++;
    }
    // 然后枚举5组字符串里面任三组中各选3个字符串
    LL res=0;
    for(int i=0;i<5;++i)
        for(int j=i+1;j<5;++j)
            for(int k=j+1;k<5;++k)
                res+=(LL)a[i]*a[j]*a[k];
    printf("%lld\n",res);
    return 0;
}