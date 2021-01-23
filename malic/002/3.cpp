#include <bits/stdc++.h>
using namespace std;

const int N= 1e5+10;
int a[N];

// 滑动窗口解决
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    sort(a,a+n);
    int res=0x3f3f3f3f;
    int left=0,right=m-1;
    while(right<n)
    {
        res=min(res,a[right]-a[left]);
        left++,right++;
    }
    printf("%d\n",res);
    return 0;
}