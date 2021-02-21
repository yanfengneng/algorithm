#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e4+10;
int a[N],l[N],r[N];

int m;

int solve(int n)
{
    memset(l,0,sizeof(int)*n),memset(r,0,sizeof(int)*n);

    // left[i]表示i左边的最大高度
    for(int i=1;i<n;++i){
        l[i]=max(l[i-1],a[i-1]);
    }

    // right[i]表示i右边的最大高度
    for(int i=n-2;i>=0;--i){
        r[i]=max(r[i+1],a[i+1]);
    }  

    int water=0;
    // 第一个位置和最后一个位置不能接雨水，因为没有完整的边界
    for(int i=1;i<n-1;++i)
    {
        // 当前位置i 能接到的雨水为当前位置i的左右高度的较小值减去当前当前高度
        // 当高度高度比左右高度都高时，相减的结果为负数，为了不失一般性，我们直接于0取max即可
        int lever=min(l[i],r[i]);
        water+=max(0,lever-a[i]);
    }
    return water; 
}

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%d",&a[i]);

        cout<<solve(n)<<endl;
    }
    return 0;
}