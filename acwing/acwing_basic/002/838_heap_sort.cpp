#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

int n,m;

// ����������Ŷ�
int h[N],size=0;

// �ݹ��
void down_1(int u)
{
    int t=u;
    // ���ж����ӽڵ��Ƿ�С�ڸ��ڵ㣬С�������uΪ���ӽڵ���
    if(u*2<=size&&h[u*2]<h[t])t=u*2;
    // ���жϸ��¹��ĸ��ڵ��ŵ�Ԫ��ֵ��ԭ���ڵ��ŵ�Ԫ��ֵ�Ƿ�С���Һ��ӽڵ㣬С�������Ϊ�Һ��ӽڵ���
    if(u*2+1<=size&&h[u*2+1]<h[t])t=2*u+1;
    // �����ڵ㲻����Сֵ�������swap
    if(u!=t)
    {
        swap(h[u],h[t]);
        down_1(t);
    }
}

// ������
void down_2(int u)
{
    while(u*2<=size)
    {
        int j=u*2;
        // Ѱ�����Һ����еĽ�Сֵ
        if(j<size&&h[j]>h[j+1])j++;
        // ɸѡ�����������ڵ�Ϊ�����ڵ��е���Сֵ�ˣ�����Ҫ�����³�������
        if(h[u]<=h[j])break;
        // �������ڵ�ͺ��ӽڵ�Ľ�Сֵ�����������³�
        swap(h[u],h[j]);
        u=j;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&h[i]);
    size=n;

    // ��[n/2,1]��ʼ�³���Ԫ�أ�ʱ�临�Ӷ�ΪO(n)����Ϊ�Ǹ��ݹ��Ҳ����д�ɵ�����
    // n/2Ϊ�����ڶ�������һ����֧�ڵ㣬Ȼ�����������һ����֧�ڵ㣬ÿ����֧�ڵ�����³�����
    for(int i=n/2;i>0;i--)down_2(i);

    while(m--)
    {
        printf("%d ",h[1]);
        // ����Ѷ�Ԫ�أ�Ȼ�󽫶ѵ�Ԫ�ظ��ǵ��Ѷ�Ԫ�أ�Ȼ���³��Ѷ�Ԫ��
        h[1]=h[size];
        size--;
        down_2(1);
    }

    return 0;
}