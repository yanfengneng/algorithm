#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
// ״̬f[i]��ʾ����a[i]��β�����������еĳ������ֵ
int n,a[N],f[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    // ö��������a[i]��β��������
    for(int i=1;i<=n;++i)
    {
        // ֻ��a[i]һ����
        f[i]=1;
        // ����״̬���㣻����j��С��i�ģ�����֮ǰ��С����ö��iʱ����iС��j�Ѿ����������
        // ��ʱ�õľ��Ǽ���������������е����ֵf[j]����������״̬ת��
        for(int j=1;j<i;++j)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
    }

    int res=0;
    // ��������е���a[i]��β��������������еõ�f[i]�󣬴���ȡһ��max���õ����մ�
    for(int i=1;i<=n;++i)res=max(f[i],res);
    cout<<res<<endl;
    return 0;
}