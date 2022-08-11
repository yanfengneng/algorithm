#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A * b：把 b 看成一个整体，然后与 A 中每一位相乘，A中的数字采用小端存储，即低位数字存储在数组的前面，高位数字存储在数组的后面
vector<int> mul(vector<int>& A,int b)
{
    vector<int> res;
    // t 表示乘法进位，这里的进位不限于0 1，可以为任意数字
    for(int i=0,t=0,n=A.size();i<n||t>0;++i)
    {
        // 获得当前位的乘积和
        if(i<n)t+=A[i]*b;
        // 添加个位数字
        res.push_back(t%10);
        // 保留进位
        t/=10;
    }

     // 如 1234 * 0 = 0000，需要删除前导0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a;int b;
    cin>>a>>b;
    vector<int> A;
    // 低位数字存储在前，高位数字存储在后
    for(int i=a.size()-1;i>=0;--i)A.push_back(a[i]-'0');
    vector<int> C=mul(A,b);
    // 从后往前打印，先打印高位数字，再打印低位数字
    for(int i=C.size()-1;i>=0;--i)printf("%d",C[i]);
    return 0;
}