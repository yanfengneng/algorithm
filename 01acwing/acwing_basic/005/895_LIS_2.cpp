#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);

    // f�����洢��������еĽ�β��Сֵ����f[i]=c����ʾ����Ϊi+1�ĵ��������еĽ�β��СֵΪc
    // �±�ͳ�����1��ƫ��
    vector<int> f;
    for(int i=0;i<n;++i)
    {
        // ������f��Ѱ�Ҵ��ڵ���a[i]��Ԫ�ص���Сλ��Ϊpos��ͬʱposҲ���±꣬��f[pos]=c��c�ǳ���Ϊpos+1���������������еĽ�β��Сֵ
        auto pos=lower_bound(f.begin(),f.end(),a[i]);
        // ���ҵ���>=a[i]����Сλ��pos�����Сֵa[i]��������c�����������ó���Ϊpos+1�������������еĽ�β��Сֵ��С����Ϊֻ�н�β��ԽС�����������еĳ���Խ��
        if(pos!=f.end())*pos=a[i];
        // ��û���ҵ�>=a[i]����Сλ��pos�������a[i]��f��β������ʾa[i]Ϊ����Ϊf.size()���������������еĽ�β��Сֵ
        else f.push_back(a[i]);
    }
    // f[n-1]=c��ʾ����Ϊn���������������еĽ�β��СֵΪc����ʱֱ�ӷ���n����ʾ��������������еĳ������ֵ
    cout<<f.size()<<endl;
    return 0;
}