#include <bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{   
    // a与0的最大公约数为a，此时的公式为 a*x+0*y=a，那么满足条件的 x=1 y=0即可
    if(b==0){
        x=1,y=0;
        return a;
    }
    // 翻转 x 和 y 的位置，更加有利于后面的计算
    int d=exgcd(b,a%b,y,x);
    // 计算公式：y*b+x*(a%b)=d，其中 a%b=a-c*b （c为a/b的商）
    // 代入公式：y*b + x*(a-c*b) = d ==>> a*x + b*(y-c*x) =d，所以此时的 y=y-c*x
    y=y-a/b*x;
    return d;
}

int  main()
{

    int n;scanf("%d",&n);
    while(n--)
    {
        int a,b,m;scanf("%d%d%d",&a,&b,&m);
        int x,y;
        int d=exgcd(a,m,x,y);
        if(b%d)puts("impossible");
        else printf("%d\n",1LL*b/d*x%m);
    }
    return 0;
}