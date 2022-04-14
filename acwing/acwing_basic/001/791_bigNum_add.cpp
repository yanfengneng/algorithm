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
        C.push_back(t%10);// 个位留下
        t/=10;// 进位保留
    }
    // 若还存在进位，则高位在补1
    if(t)C.push_back(1);
    return C;
}

int main()
{
    string a,b;
    vector<int> A,B;

    cin>>a>>b;// a = "123456"
    // size为无符号数，size-1之后会被转换为int的，也就是-1，若直接输出size-1，会直接输出-1的补码
    // 数组中最高位(最大值位)是存放在数组尾部的，个位(最低位)是存放在数组前面的
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');// A = [6 5 4 3 2 1]
    for(int i=b.size()-1;i>=0;--i)B.push_back(b[i]-'0');

    vector<int> C=add(A,B);

    // 数组中最高位(最大值位)是存放在数组尾部的，个位(最低位)是存放在数组前面的
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    return 0;
}