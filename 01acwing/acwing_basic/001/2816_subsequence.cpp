#include <iostream>
using namespace std;

const int N = 1e5+10;
int a[N],b[N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<m;++i)scanf("%d",&b[i]);

    // ��ָ��i��ɨ������a��ָ��j��ɨ������b
    // ����������jָ�벻���ƶ�����ָ��iֻ��Ԫ��ƥ��ɹ�ʱ�����ƶ�һλ
    int i=0;
    for(int j=0;j<m;++j)
    {
        if(i<n&&a[i]==b[j])i++;
    }
    if(i==n)printf("Yes\n");
    else printf("No\n");
    return 0;
}