#include <bits/stdc++.h>
using namespace std;

// �߾��� / �;��ȣ�A / b
vector<int> div(vector<int>& A,int b,int& r)
{
    vector<int> res;
    // r Ϊ����
    r=0;
    // �������ǴӸ�λ����λ��ʼ�����
    // ������ֵ�ǰ�С�˴洢�������еģ���˸�λ������������档�������ǵ�����㡣
    for(int i=A.size()-1;i>=0;i--)
    {
        // ��ǰλ�ı�����
        r=r*10+A[i];
        // ������ӵ� res �У�ע�������Ǹ�λ��ӵ�����ǰ���
        res.push_back(r/b);
        // ��������
        r%=b;
    }
    // ��ת res���õ�λ��ǰ����λ�ں���ǰ����������㱣��һ��
    reverse(res.begin(),res.end());
    // ȥ��ǰ�� 0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a;int b;
    cin>>a>>b;
    vector<int> A;
    // ����洢����λ���ִ洢��ǰ����λ���ִ洢�ں�
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    // r ��ʾ����
    int r;
    auto res=div(A,b,r);
    // �����ӡ���֣����Ӹ�λ����λ��ӡ
    for(int i=res.size()-1;i>=0;i--)cout<<res[i];
    cout<<endl<<r<<endl;
    return 0;
}