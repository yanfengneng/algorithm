#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &A, vector<int>& B)
{
    vector<int> res;
    // ������λ������ӵĽ�λ���Ϊ1������������λ������ӣ�9+9 = 18���ټ���һ����λ 1�����ս��ҲΪ 19��������ֽ�λ 2 �������
    int n=A.size(),m=B.size(),carry=0;
    for(int i=0;i<n||i<m;++i){
        if(i<n)carry+=A[i];
        if(i<m)carry+=B[i];
        res.push_back(carry%10);
        carry/=10;
    }
    // �������ڽ�λ�����ڸ�λ��1
    if(carry)res.push_back(1);
    // ���ս��Ҳ��С�˴洢����˴Ӻ���ǰ��ӡ�������մ�
    return res;
}

int main()
{
    string a,b;cin>>a>>b;
    // ����С�˴洢������λ���ִ洢��ǰ����λ���ִ洢�ں󣬱��ڽ���λ�Ľ��ֱ����ӽ��������棬���ò�����������λ�����ʱ����˷�
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    auto C=add(A,B);
    // ���ս��Ҳ��С�˴洢����˴Ӻ���ǰ��ӡ�������մ�
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    return 0;
}