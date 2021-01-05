#include <iostream>
using namespace std;

const int N=1e6+10;

int n;
int q[N],temp[N];

// 归并排序--分治算法，利用递归解决的
void merge_sort(int q[],int l,int r)
{
    // 区间内只有一个元素或没有元素内，不能继续递归了
    if(l>=r)return;

    // 1、确定分界点
    int mid=l+r>>1;

    // 2、递归排序左右两个序列
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);

    // 3、归并--合二为一
    // i指向左半边的第一个位置，j指向右半边的第一个位置
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])temp[k++]=q[i++];// 插入较小的q[i]
        else temp[k++]=q[j++];// 插入较小的q[j]
    }
    // 两个序列中有一个没插完，把剩下那个序列插完到temp中
    while(i<=mid)temp[k++]=q[i++];// 左半部分没插完，现在全部插入进去
    while(j<=r)temp[k++]=q[j++];

    // 还原排好序的数组q
    for(i=l,j=0;i<=r;i++,j++)q[i]=temp[j];
}

int main()
{
    // scanf输入要加地址符&，printf不要加地址符&
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);

    merge_sort(q,0,n-1);

    for(int i=0;i<n;++i)printf("%d ",q[i]);
    return 0;
}
