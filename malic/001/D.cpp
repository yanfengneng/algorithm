#include <bits/stdc++.h>

using namespace std;

vector<int> a(2e5+10,0),cnt(1e6+10,0);
set<int> visited;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    sort(a.begin(),a.begin()+n);

    // ��ʾ��������ֵ��������Ҫ����maxA�����������a[i]�ı������б�ǣ���ʾ�ɱ�������������ɸ��
    int maxA=a[n-1];
    for(int i=0;i<n;++i)
    {
        // ��ͬһԪ�س��ֶ�Σ�����set����¼����ʾ������
        if(visited.count(a[i])>0)cnt[a[i]]=1;
        else visited.insert(a[i]);

        // ����ֵΪ1��ʾ�ܱ�a[i]����
        for(int j=2*a[i];j<=maxA;j+=a[i])cnt[j]=1;
    }

    int res=0;
    // cnt[a[i]]==0�ı�ʾ���ᱻ�κ�Ԫ�������ģ�����1��Ϊ�ɱ�����Ԫ������
    for(int i=0;i<n;++i)
    {
        if(!cnt[a[i]])res++;
    }
    cout<<res<<endl;
    return 0;
}