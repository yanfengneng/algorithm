#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int a[N],b[N];
int n;

// ��Ⱥ���صĺ�������Ϊ x�����ص�Ϊ y�� ץ�� x ������,y �ɵ������������춼�� x ��������
int main()
{
    /*cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    memcpy(b,a,sizeof(int)*n);
    sort(b,b+n);

    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[n-1])cout<<b[n-1]<<endl;
        else cout<<b[n-2]<<endl;
    }*/

    // ������������֮�⣬���Ա߳���߼�¼���ֵ�ʹ����ֵ
    cin>>n;
    int x=-1,y=-1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>x)// �������ֵ�ʹ����ֵ
        {
            y=x;
            x=a[i];
            continue;
        }
        // ���´����ֵ
        if(a[i]>y)y=a[i];
    }

    for(int i=0;i<n;++i)
    {
        // �ж����ֵx�Ƿ�ץ���ˣ���ץ���˾�y��������û��ץ�߾�x������
        if(a[i]!=x)cout<<x<<endl;
        else cout<<y<<endl;
    }
    return 0;
}