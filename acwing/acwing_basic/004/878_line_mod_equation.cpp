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
        // 题目要求的方程为：a*x=m*y+b 其中y为商。移项得：a*x+m*y1=b 其中y1=-y，由于题目只要求我们求x，所以不用管y。
        // 上式就转换为扩展欧几里得等式了，我们先求出来a*x+m*y1 = gcd(a,m) = d的最大公约数d，然后判断b是否是d的倍数即可。若b是d的倍数，则说明有解；否则就无解。
        // 若有解，只需要将等式两边同时扩大 b/d 倍就可以得到等式右边的 b 了，即(b/d)*(a*x+m*y1)=(b/d)*d ==>> a*x*b/d+m*y*b/d = b 所以此时a的系数 x*b/d 即为题目所求的解。
        int d=exgcd(a,m,x,y);
        if(b%d)puts("impossible");
        else printf("%d\n",1LL*b/d*x%m);
    }
    return 0;
}