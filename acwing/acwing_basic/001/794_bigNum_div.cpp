#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int>& A,int b,int& r)
{
    vector<int> C;
    r=0;
    // 除法是从最高位开始除的
    for(int i=A.size()-1;i>=0;--i)
    {
        // 上一位的余数拿下来的时候要*10，然后加上该位数字，进行除法
        r=r*10+A[i];
        // 添加商，保留余数
        C.push_back(r/b);
        r%=b;
    }   
    // 由于最高位先被存放在数组前面的，所以要反转一下，使商倒着存放在C中
    reverse(C.begin(),C.end());

    // 除去前导 0
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;

    cin>>a>>b;

    vector<int> A;
    // 数是倒着存的
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');


    int r;// r 为余数
    vector<int> C=div(A,b,r);

    for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    cout<<endl<<r<<endl;

    return 0;
}