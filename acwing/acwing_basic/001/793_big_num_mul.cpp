#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A * b���� b ����һ�����壬Ȼ���� A ��ÿһλ��ˣ�A�е����ֲ���С�˴洢������λ���ִ洢�������ǰ�棬��λ���ִ洢������ĺ���
vector<int> mul(vector<int>& A,int b)
{
    vector<int> res;
    // t ��ʾ�˷���λ������Ľ�λ������0 1������Ϊ��������
    for(int i=0,t=0,n=A.size();i<n||t>0;++i)
    {
        // ��õ�ǰλ�ĳ˻���
        if(i<n)t+=A[i]*b;
        // ��Ӹ�λ����
        res.push_back(t%10);
        // ������λ
        t/=10;
    }

     // �� 1234 * 0 = 0000����Ҫɾ��ǰ��0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a;int b;
    cin>>a>>b;
    vector<int> A;
    // ��λ���ִ洢��ǰ����λ���ִ洢�ں�
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');
    vector<int> C=mul(A,b);
    // �Ӻ���ǰ��ӡ���ȴ�ӡ��λ���֣��ٴ�ӡ��λ����
    for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    return 0;
}