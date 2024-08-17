#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5+10;
int a[N];

void quick_sort(int q[],int l,int r)
{
    if(l>=r)return;

    int x=a[l+r>>1],i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    quick_sort(q,l,j),quick_sort(q,j+1,r);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    
    // 不管n是奇数还是偶数，建在中位数位置都是最优解
    int mid=a[n/2];

    long long res=0;
    for(int i=0;i<n;++i)res+=abs(mid-a[i]);
    printf("%d",res);
    return 0;
}