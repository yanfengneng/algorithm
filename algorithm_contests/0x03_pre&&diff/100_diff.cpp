#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using LL = long long;
int a[N],n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    // ������������
    for(int i=n;i>1;i--)a[i]-=a[i-1];
    // ͳ�Ʋ������[2,n]�е�������pos�͸����͵ľ�����neg
    LL pos=0,neg=0;
    for(int i=2;i<=n;++i)
        if(a[i]>0)pos+=a[i];
        else neg-=a[i];
    // ���ٲ�����Ϊmin(pos,neg)+abs(pos-neg)=max(pos,neg)���ܲ���abs(pos-neg)+1�ֲ�ͬ��b1ֵ
    printf("%lld\n",max(pos,neg));
    printf("%lld\n",abs(pos-neg)+1);
    return 0;
}