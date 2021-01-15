#include <iostream>
#include <cstring>
using namespace std;

// 利用链地址法来解决冲突的hash来做

const int N = 1e5+10;
// tt使用过那些下标，要用是要把tt+1
int n,tt=0,p=99991;

// head存放的是哈希值。next存放的是同一个哈希值对应的一个链表的下标
int snow[N][6],head[N],nxt[N];

// hash函数计算hash值，对于形状相同的雪花，它们6条边的和、积都相等，因此它们的hash值也相等
int H(int a[])
{
    int sum=0,mul=1;
    for(int i=0;i<6;++i)
    {
        sum=(sum+a[i])%p;
        mul=(long long)mul*a[i]%p;
    }
    return (sum+mul)%p;
}

// 判断两片雪花是否相等
bool equal(int a[],int b[])
{
    for(int i=0;i<6;++i)
        for(int j=0;j<6;++j)
        {
            bool eq=1;
            // 两片雪花相同方向和下相反方向都判断下
            for(int k=0;k<6;++k)
                if(a[(i+k)%6]!=b[(j+k)%6])eq=0;
            if(eq)return 1;
            eq=1;
            for(int k=0;k<6;++k)
                if(a[(i+k)%6]!=b[(j-k+6)%6])eq=0;
            if(eq)return 1;
        }
    return 0;
}

bool insert(int a[])
{
    int val=H(a);
    // 遍历表头head[val]指向的是链表，寻找形状相同的雪花，0表示空
    for(int i=head[val];i!=0;i=nxt[i])
        if(equal(snow[i],a))return 1;
    // 未找到形状相同的雪花，执行插入
    ++tt;
    memcpy(snow[tt],a,6*sizeof(int));

    // 链表的头插法
    nxt[tt]=head[val];
    head[val]=tt;
    return 0;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int a[10];
        for(int i=0;i<6;++i)scanf("%d",&a[i]);
        if(insert(a))
        {
            puts("Twin snowflakes found.");
            return 0;
        }
    }
    puts("No two snowflakes are alike.");
    return 0;
}