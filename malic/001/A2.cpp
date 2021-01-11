#include <iostream>
using namespace std;

// 学一下malic的思路吧，我是用区间贪心合并区间做的，马老师用的数组记录一下出现的数字，最后在遍历数组就行了

int cnt[400];
int n;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;++i)cnt[i]=1;
    }

    int res=0;
    for(int i=1;i<=366;++i)
        if(cnt[i])res++;
    printf("%d\n",res);
    return 0;
}