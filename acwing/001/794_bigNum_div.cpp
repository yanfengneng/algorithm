#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int>& A,int b,int& r)
{
    vector<int> C;
    r=0;
    // �����Ǵ����λ��ʼ����
    for(int i=A.size()-1;i>=0;--i)
    {
        // ��һλ��������������ʱ��Ҫ*10��Ȼ����ϸ�λ���֣����г���
        r=r*10+A[i];
        // ����̣���������
        C.push_back(r/b);
        r%=b;
    }   
    // �������λ�ȱ����������ǰ��ģ�����Ҫ��תһ�£�ʹ�̵��Ŵ����C��
    reverse(C.begin(),C.end());

    // ��ȥǰ�� 0
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;

    cin>>a>>b;

    vector<int> A;
    // ���ǵ��Ŵ��
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');


    int r;// r Ϊ����
    vector<int> C=div(A,b,r);

    for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    cout<<endl<<r<<endl;

    return 0;
}