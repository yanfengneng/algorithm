#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> add(vector<int>& A,vector<int>& B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||i<B.size();++i)
    {
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);// ��λ����
        t/=10;// ��λ����
    }
    // �������ڽ�λ�����λ�ڲ�1
    if(t)C.push_back(1);
    return C;
}

int main()
{
    string a,b;
    vector<int> A,B;

    cin>>a>>b;// a = "123456"
    // sizeΪ�޷�������size-1֮��ᱻת��Ϊint�ģ�Ҳ����-1����ֱ�����size-1����ֱ�����-1�Ĳ���
    // ���������λ(���ֵλ)�Ǵ��������β���ģ���λ(���λ)�Ǵ��������ǰ���
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');// A = [6 5 4 3 2 1]
    for(int i=b.size()-1;i>=0;--i)B.push_back(b[i]-'0');

    vector<int> C=add(A,B);

    // ���������λ(���ֵλ)�Ǵ��������β���ģ���λ(���λ)�Ǵ��������ǰ���
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    return 0;
}