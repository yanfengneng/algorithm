#include <bits/stdc++.h>
using namespace std;

int n;
int a[3],b[3];

int single()
{
    int res=1;
    // n大于等于5的话，每一位只有5种选法；n小于5的话，每一位只有n种选法了
    for(int i=0;i<3;++i)
        res*=min(5,n);
}

int both()
{
    if(n<=5)return n*n*n;
    int res=1;
    for(int i=0;i<3;++i){
        int d=abs(a[i]-b[i]);
        // 距离为d，公共可选点为5-d个，正向为5-d个，反向为5-(n-d)个，只有一个成立
        res*=max(0,5-d)+max(0,5-(n-d));
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;++i)scanf("%d",&a[i]);
    for(int i=0;i<3;++i)scanf("%d",&b[i]);

    cout<<single()*2-both()<<endl;
    return 0;
}