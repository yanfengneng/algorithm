#include <iostream>

using namespace std;

// typedef 类型别名写在最后面
// int 的最大值为2*1e9，而1e5数据的最大逆序数达到5*1e9了，会爆 int，因此改用 long long
typedef long long LL;
const int N=1e5+10;
int q[N],tmp[N];

int n;

LL memge_sort(int l,int r)
{
    // 区间内只有一个数或者没有数时，不用继续归并了
    if(l>=r)return 0;

    // 1、确定分界点和进行递归排序，类试树的后续遍历，左右根
    LL mid=l+r>>1;
    LL res=memge_sort(l,mid)+memge_sort(mid+1,r);

    // 2、归并过程--合二为一
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else
        {
            tmp[k++]=q[j++];
            // 由于q[i]>q[j]，那么q[i~mid]都要比q[j]大，都会构成逆序对
            res+=mid-i+1;
        }
        
    }

    // 3、扫尾工作--处理好剩下没插入的部分
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];

    // 4、还原数组q[]
    for(int i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];

    // 卧槽，这个不能掉啊！！！
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);
    cout<<memge_sort(0,n-1)<<endl;
    return 0;
}