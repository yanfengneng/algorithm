#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &A, vector<int>& B)
{
    vector<int> res;
    // 两个个位数字相加的进位最多为1，如两个最大个位数字相加：9+9 = 18；再加上一个进位 1，最终结果也为 19，不会出现进位 2 的情况。
    int n=A.size(),m=B.size(),carry=0;
    for(int i=0;i<n||i<m;++i){
        if(i<n)carry+=A[i];
        if(i<m)carry+=B[i];
        res.push_back(carry%10);
        carry/=10;
    }
    // 若还存在进位，则在高位补1
    if(carry)res.push_back(1);
    // 最终结果也是小端存储，因此从后往前打印才是最终答案
    return res;
}

int main()
{
    string a,b;cin>>a>>b;
    // 采用小端存储，即低位数字存储在前，高位数字存储在后，便于将进位的结果直接添加结果数组后面，不用插入结果数组首位，造成时间的浪费
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    auto C=add(A,B);
    // 最终结果也是小端存储，因此从后往前打印才是最终答案
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    return 0;
}