#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string A,B;
    cin>>A>>B;

    int n=A.size();
    for(int i=0;i<n;++i)
    {
        if(A==B)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        // ��A�ĵ�һ���ַ���ת�������ȥ
        // rotate(A.begin(),A.begin()+1,A.end());
        // ��һ��д��
        char t=A[0];
        for(int j=1;j<n;++j)
            A[j-1]=A[j];
        A.back()=t;
    }
    cout<<"No"<<endl;
    return 0;
}
