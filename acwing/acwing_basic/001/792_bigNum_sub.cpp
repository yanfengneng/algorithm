#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 判断是否有 A >= B
bool cmp(vector<int>& A,vector<int>& B)
{
    // 位数多的数，大
    if(A.size()!=B.size())return A.size()>B.size();
    // A与B的位数相同，由于数是倒序存放的，因为从最后面，也就是最高位开始比
    for(int i=A.size()-1;i>=0;--i)
    {
        if(A[i]!=B[i])return A[i]>B[i];
    }
    // A与B相等，返回true
    return true;
}

// C = A - B
vector<int> sub(vector<int>& A,vector<int>& B)
{
    vector<int> C;
    // 由于保证了 A>=B，所以i只要小于A的位数就行了
    // t表示借位哈，每次A[i]-B[i]-t
    for(int i=0,t=0;i<A.size();++i)
    {
            t=A[i]-t;
            if(i<B.size())t-=B[i];// B 还有位数，要用来相减
            C.push_back((t+10)%10);// 避免分情况讨论，t大于0，+10取余之后位t本身；t小于0，+10取余之后表示正常的借位之后的值
            // t<0表示有借位，并且两数相减，借位最多为1；否则就没有借位，直接当前相对应位数相减
            if(t<0)t=1;
            else t=0;
    }
    // 如123-120=003,003倒放在数组为300，我们要去掉多余的0，且结果本来为0的话，就不要去掉0了
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
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