#include <iostream>
using namespace std;

const int N= 1e5+10;
int a[N],b[N];
int n,m,x;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    
    // ָ�� i ��ǰ����ɨ������ a��ָ�� j �Ӻ���ǰɨ������ b
    for(int i=0,j=m-1;i<n;++i)
    {
        // ��a[i]+b[j]>k�Ļ�����ô��ʹi����֮��������ӵĽ�����ǻ����x��
        // ���ֻ������ָ��j����Ѱ�Һ͵���x��ע����������������ģ��ú������������
        while(j>=0&&a[i]+b[j]>x)j--;
        if(j>=0&&a[i]+b[j]==x)cout<<i<<" "<<j<<endl;
    }
    return 0;
}