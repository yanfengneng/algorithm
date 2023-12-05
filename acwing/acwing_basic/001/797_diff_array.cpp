#include <iostream>
using namespace std;

const int N=100010;
int a[N],b[N];

void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    // 构造差分数组
    for(int i=1;i<=n;++i)b[i]=a[i]-a[i-1];

    while(m--)
    {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        // [l,n]全部加c，[r+1,n]全部减c，这样[l,r]全部加上c了
        insert(l,r,c);
    }

    for(int i=1;i<=n;++i){
        b[i]+=b[i-1];// 将差分数组还原为插入区间值之后的数组，即求前缀和
        printf("%d ",b[i]);
    }

    return 0;
}