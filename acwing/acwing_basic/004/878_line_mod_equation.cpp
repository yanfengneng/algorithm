#include <bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{   
    // a��0�����Լ��Ϊa����ʱ�Ĺ�ʽΪ a*x+0*y=a����ô���������� x=1 y=0����
    if(b==0){
        x=1,y=0;
        return a;
    }
    // ��ת x �� y ��λ�ã����������ں���ļ���
    int d=exgcd(b,a%b,y,x);
    // ���㹫ʽ��y*b+x*(a%b)=d������ a%b=a-c*b ��cΪa/b���̣�
    // ���빫ʽ��y*b + x*(a-c*b) = d ==>> a*x + b*(y-c*x) =d�����Դ�ʱ�� y=y-c*x
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