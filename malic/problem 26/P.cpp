#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e4+10;
int a[N],l[N],r[N];

int m;

int solve(int n)
{
    memset(l,0,sizeof(int)*n),memset(r,0,sizeof(int)*n);

    // left[i]��ʾi��ߵ����߶�
    for(int i=1;i<n;++i){
        l[i]=max(l[i-1],a[i-1]);
    }

    // right[i]��ʾi�ұߵ����߶�
    for(int i=n-2;i>=0;--i){
        r[i]=max(r[i+1],a[i+1]);
    }  

    int water=0;
    // ��һ��λ�ú����һ��λ�ò��ܽ���ˮ����Ϊû�������ı߽�
    for(int i=1;i<n-1;++i)
    {
        // ��ǰλ��i �ܽӵ�����ˮΪ��ǰλ��i�����Ҹ߶ȵĽ�Сֵ��ȥ��ǰ��ǰ�߶�
        // ���߶ȸ߶ȱ����Ҹ߶ȶ���ʱ������Ľ��Ϊ������Ϊ�˲�ʧһ���ԣ�����ֱ����0ȡmax����
        int lever=min(l[i],r[i]);
        water+=max(0,lever-a[i]);
    }
    return water; 
}

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%d",&a[i]);

        cout<<solve(n)<<endl;
    }
    return 0;
}