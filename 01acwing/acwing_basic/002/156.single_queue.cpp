#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6+10;
int a[N];

// 用数组模拟队列，hh表示队头，tt表示队尾
// q存的是数组a的下标
int q[N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);

    int hh=0,tt=-1;
    // 寻找窗口内的最小值--单调递减队列（队头元素最小）
    for(int i=0;i<n;++i)
    {   
        // 判断队头是否已经滑出窗口，因为只有一个数不在窗口内，所以只用一个if就行了
        if(hh<=tt&&i-k+1>q[hh])hh++;

        // 队头的值比a[i]大，也就是前面的点的值比后面点的值还要大，我们断定前面的点没有用，因此队头出队列
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;

        // 把当前下标插入到队列中
        q[++tt]=i;

        // 下标为k-1表示第k个数，当i>=k-1时，表示我们的窗口内已经有k个数字了可以输出最小值了
        if(i>=k-1)printf("%d ",a[q[hh]]);
    }  

    // 接受回车的或者空格
    puts("");

    // 寻找窗口内的最大值--单调递增队列（队头元素最大）
    hh=0,tt=-1;
    for(int i=0;i<n;++i)
    {   
        // 判断队头是否已经滑出窗口，因为只有一个数不在窗口内，所以只用一个if就行了
        if(hh<=tt&&i-k+1>q[hh])hh++;

        // 队头的值比a[i]小，也就是前面的点的值比后面点的值还要小，我们断定前面的点没有用，因此队头出队列
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;

        // 把当前下标插入到队列中
        q[++tt]=i;

        // 下标为k-1表示第k个数，当i>=k-1时，表示我们的窗口内已经有k个数字了可以输出最小值了
        if(i>=k-1)printf("%d ",a[q[hh]]);
    } 
    puts("");

    return 0;
}