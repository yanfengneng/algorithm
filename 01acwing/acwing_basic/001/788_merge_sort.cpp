#include <iostream>

using namespace std;

// typedef ���ͱ���д�������
// int �����ֵΪ2*1e9����1e5���ݵ�����������ﵽ5*1e9�ˣ��ᱬ int����˸��� long long
typedef long long LL;
const int N=1e5+10;
int q[N],tmp[N];

int n;

LL memge_sort(int l,int r)
{
    // ������ֻ��һ��������û����ʱ�����ü����鲢��
    if(l>=r)return 0;

    // 1��ȷ���ֽ��ͽ��еݹ������������ĺ������������Ҹ�
    LL mid=l+r>>1;
    LL res=memge_sort(l,mid)+memge_sort(mid+1,r);

    // 2���鲢����--�϶�Ϊһ
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else
        {
            tmp[k++]=q[j++];
            // ����q[i]>q[j]����ôq[i~mid]��Ҫ��q[j]�󣬶��ṹ�������
            res+=mid-i+1;
        }
        
    }

    // 3��ɨβ����--�����ʣ��û����Ĳ���
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];

    // 4����ԭ����q[]
    for(int i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];

    // �Բۣ�������ܵ���������
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);
    cout<<memge_sort(0,n-1)<<endl;
    return 0;
}