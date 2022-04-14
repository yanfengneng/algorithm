#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

int n,m;

// 用数组来存放堆
int h[N],size=0;

// 递归版
void down_1(int u)
{
    int t=u;
    // 先判断左孩子节点是否小于父节点，小于则更新u为左孩子节点编号
    if(u*2<=size&&h[u*2]<h[t])t=u*2;
    // 再判断更新过的父节点编号的元素值或原父节点编号的元素值是否小于右孩子节点，小于则更新为右孩子节点编号
    if(u*2+1<=size&&h[u*2+1]<h[t])t=2*u+1;
    // 若根节点不是最小值，则进行swap
    if(u!=t)
    {
        swap(h[u],h[t]);
        down_1(t);
    }
}

// 迭代版
void down_2(int u)
{
    while(u*2<=size)
    {
        int j=u*2;
        // 寻找左右孩子中的较小值
        if(j<size&&h[j]>h[j+1])j++;
        // 筛选结束，即根节点为三个节点中的最小值了，不需要进行下沉操作了
        if(h[u]<=h[j])break;
        // 交换根节点和孩子节点的较小值，继续迭代下沉
        swap(h[u],h[j]);
        u=j;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&h[i]);
    size=n;

    // 从[n/2,1]开始下沉堆元素，时间复杂度为O(n)，因为那个递归版也可以写成迭代版
    // n/2为倒数第二层的最后一个分支节点，然后倒序遍历到第一个分支节点，每个分支节点进行下沉操作
    for(int i=n/2;i>0;i--)down_2(i);

    while(m--)
    {
        printf("%d ",h[1]);
        // 输出堆顶元素，然后将堆底元素覆盖到堆顶元素，然后下沉堆顶元素
        h[1]=h[size];
        size--;
        down_2(1);
    }

    return 0;
}