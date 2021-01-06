#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �ж��Ƿ��� A >= B
bool cmp(vector<int>& A,vector<int>& B)
{
    // λ�����������
    if(A.size()!=B.size())return A.size()>B.size();
    // A��B��λ����ͬ���������ǵ����ŵģ���Ϊ������棬Ҳ�������λ��ʼ��
    for(int i=A.size()-1;i>=0;--i)
    {
        if(A[i]!=B[i])return A[i]>B[i];
    }
    // A��B��ȣ�����true
    return true;
}

// C = A - B
vector<int> sub(vector<int>& A,vector<int>& B)
{
    vector<int> C;
    // ���ڱ�֤�� A>=B������iֻҪС��A��λ��������
    // t��ʾ��λ����ÿ��A[i]-B[i]-t
    for(int i=0,t=0;i<A.size();++i)
    {
            t=A[i]-t;
            if(i<B.size())t-=B[i];// B ����λ����Ҫ�������
            C.push_back((t+10)%10);// �����������ۣ�t����0��+10ȡ��֮��λt����tС��0��+10ȡ��֮���ʾ�����Ľ�λ֮���ֵ
            // t<0��ʾ�н�λ�����������������λ���Ϊ1�������û�н�λ��ֱ�ӵ�ǰ���Ӧλ�����
            if(t<0)t=1;
            else t=0;
    }
    // ��123-120=003,003����������Ϊ300������Ҫȥ�������0���ҽ������Ϊ0�Ļ����Ͳ�Ҫȥ��0��
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

int main()
{
    string a,b;
    vector<int> A,B;

    cin>>a>>b;// a = "123456"
    // ���������λ(���ֵλ)�Ǵ��������β���ģ���λ(���λ)�Ǵ��������ǰ���
    // ���ǰѸ�λ���ִ����������ǰ�棬���ֵ���ִ������������棬���ڽ�λ
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');// A = [6 5 4 3 2 1]
    for(int i=b.size()-1;i>=0;--i)B.push_back(b[i]-'0');

    if(cmp(A,B))
    {
        vector<int> C=sub(A,B);
        for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    }
    else
    {
        vector<int> C=sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    }
    return 0;
}