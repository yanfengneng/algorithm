#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 判断是否有 A >= B
bool cmp(vector<int>& A,vector<int>& B)
{
    // 两个数的位数不同，位数越大的数值就越大
    if(A.size()!=B.size())return A.size()>B.size();
    // 位数相同的话，就从高位到低位开始比较。由于数值是小端存储，高位数字在后，因此从后到往前比较比较
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=B[i])return A[i]>B[i];
    // A B相等，返回true
    return true;
}

// A>=0 B>=0 A>=B
vector<int> sub(vector<int>& A,vector<int>& B)
{
    vector<int> res;
    // t表示借位，若借了该位，t=1；若没有借该位，t=0；
    int t=0;
    // 由于规定了A>=B，所以A的位数大于等于B的位数，每次需要判断下标i是否超过B的大小即可
    for(int i=0,n=A.size(),m=B.size();i<n;++i)
    {
        // 当前位的计算值为 c = A[i]-B[i]-t。若 c >=0，则当前位不需要高位借位，令t=0即可；若 c<0，则当前位需要向高位借1，令t=1即可
        t=A[i]-t;
        // 没超过数值 B 的范围，则继续相减
        if(i<m)t-=B[i];
        // 两位数字相减，结果要么是一位正数，要么是一位负数
        // 当结果 t>=0 时，当前位的计算结果就是t；当结果 t<0 时，需要向高位借 1，也就是当前的结算结果需要加上 10。综合起来，当前位的计算结果为 (t+10)%10
        res.push_back((t+10)%10);
        // 处理当前位的借位：t>=0 不需要借位，令 t=0；t<0 需要借位，令t=1。
        if(t>=0)t=0;
        else t=1;
    }
    // 计算的结果是低位数字存储在 res 的前面，因此高位数字得到前导0存储在数组后面，需要进行删除
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a,b;
    vector<int> A,B;

    cin>>a>>b;// a = "123456"
    // 数组中最高位(最大值位)是存放在数组尾部的，个位(最低位)是存放在数组前面的
    // 我们把个位数字存在数组的最前面，最大值数字存在数组的最后面，便于借位
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