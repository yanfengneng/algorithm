#include <bits/stdc++.h>
using namespace std;

// 高精度 / 低精度：A / b
vector<int> div(vector<int>& A,int b,int& r)
{
    vector<int> res;
    // r 为余数
    r=0;
    // 做除法是从高位到低位开始计算的
    // 由于数值是按小端存储在数组中的，因此高位数字在数组后面。所以我们倒序计算。
    for(int i=A.size()-1;i>=0;i--)
    {
        // 当前位的被除数
        r=r*10+A[i];
        // 将商添加到 res 中，注意这里是高位添加到数组前面的
        res.push_back(r/b);
        // 保留余数
        r%=b;
    }
    // 翻转 res，让低位在前，高位在后，与前面的三种运算保持一致
    reverse(res.begin(),res.end());
    // 去除前导 0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a;int b;
    cin>>a>>b;
    vector<int> A;
    // 倒序存储，低位数字存储在前，高位数字存储在后
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    // r 表示余数
    int r;
    auto res=div(A,b,r);
    // 倒序打印数字，即从高位到低位打印
    for(int i=res.size()-1;i>=0;i--)cout<<res[i];
    cout<<endl<<r<<endl;
    return 0;
}