#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e5+10;
int n,m;
// ��������
int a[N];
// tree1[i]�洢�������b[i]��tree2[i]�洢i*b[i]
LL tree1[N],tree2[N];

int lowbit(int x)
{
    return x&-x;
}

// ��ǰx����ܺ�
LL sum(LL tree[],int x)
{
    LL res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=tree[i];
    return res;
}

// �ڵ�x��λ�ü���v��v����Ҫ��LL ��ֹ��int
void add(LL tree[],int x,LL v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=v;
}

// ��ǰ׺��
LL prefix_sum(int x)
{
    return sum(tree1,x)*(x+1)-sum(tree2,x);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);

    for(int i=1;i<=n;++i)
    {
        // �������
        int b=a[i]-a[i-1];
        // a[l,r]����ӷ���ɵ�ӷ�b[l]+=c,b[r+1]-=c
        add(tree1,i,b);
        // ����ͱ�ɵ�ͣ�a[l...r]=b[1...l]+b[1...(l+1)]+...b[1...r]=(x+1)*b[1...x]-(b1*1+b2*2+...+bx*x)
        add(tree2,i,1LL*i*b);
    }

    while(m--)
    {
        char op[2];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if(*op=='C')
        {
            scanf("%d",&d);
            // b[l]+=d
            add(tree1,l,d),add(tree2,l,1LL*l*d);
            // b[r+1]-=d
            add(tree1,r+1,-d),add(tree2,r+1,(r+1)*-d);
        }
        else{
            printf("%lld\n", prefix_sum(r)-prefix_sum(l - 1));
        }
    }
    return 0;
}