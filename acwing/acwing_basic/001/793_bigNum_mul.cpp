#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A,int b)
{
    vector<int> C;
    // t ��ʾ��λ
    for(int i=0,t=0;i<A.size()||t!=0;++i)
    {
        if(i<A.size())t+=A[i]*b;
        C.push_back(t%10);// ��Ӹ�λ
        t/=10;// ������λ
    }
    // ��1234 * 0 =0000������Ҫɾ��ǰ��0
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;

    cin>>a>>b;

    vector<int> A;
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');
    vector<int> C=mul(A,b);
    for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    return 0;
}