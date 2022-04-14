#include <iostream>
using namespace std;

const int N=1e6+10;

int n;
int q[N],temp[N];

// �鲢����--�����㷨�����õݹ�����
void merge_sort(int q[],int l,int r)
{
    // ������ֻ��һ��Ԫ�ػ�û��Ԫ���ڣ����ܼ����ݹ���
    if(l>=r)return;

    // 1��ȷ���ֽ��
    int mid=l+r>>1;

    // 2���ݹ�����������������
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);

    // 3���鲢--�϶�Ϊһ
    // iָ�����ߵĵ�һ��λ�ã�jָ���Ұ�ߵĵ�һ��λ��
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])temp[k++]=q[i++];// �����С��q[i]
        else temp[k++]=q[j++];// �����С��q[j]
    }
    // ������������һ��û���꣬��ʣ���Ǹ����в��굽temp��
    while(i<=mid)temp[k++]=q[i++];// ��벿��û���꣬����ȫ�������ȥ
    while(j<=r)temp[k++]=q[j++];

    // ��ԭ�ź��������q
    for(i=l,j=0;i<=r;i++,j++)q[i]=temp[j];
}

int main()
{
    // scanf����Ҫ�ӵ�ַ��&��printf��Ҫ�ӵ�ַ��&
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);

    merge_sort(q,0,n-1);

    for(int i=0;i<n;++i)printf("%d ",q[i]);
    return 0;
}
