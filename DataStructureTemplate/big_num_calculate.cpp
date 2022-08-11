#include <bits/stdc++.h>
using namespace std;

// 高精度加法
string add(const string& a,const string& b)
{
    string c;
    // 保留两个个位数字相加的进位
    int t=0;
    // 从低位开始向高位进行运算，相加的结果是从低位往高位进行存储的，因此最终结果还要进行翻转，才能成为正确的数字
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t;i--,j--)
    {
        if(i>=0)t+=a[i]-'0';
        if(j>=0)t+=b[j]-'0';
        c.push_back('0'+(t%10));
        t/=10;
    }
    // 由于得到的结果是低位数字先被存储的，因此需要进行翻转才能成为正确结果
    // 加法不会出现高位出现前导 0 的情况
    reverse(c.begin(),c.end());
    return c;
}

// 高精度减法：使用大数减小数，这样一定不会出现负数的情况。因此最高位是一定不会出现借位的情况的，可以少处理一些边界问题。
// A>=0 B>=0 且 A>=B
string sub(const string& a,const string& b)
{
    // 计算的结果是高位先存储在 res 中的，因此最终还要将 res 进行翻转
    string res;
    // t 表示借位
    int t=0;
    // 从低位到高位开始计算
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t;i--,j--)
    {   
        // 当前位的计算结果为 A[i]-B[i]-t
        if(i>=0)t=(a[i]-'0')-t;
        if(j>=0)t-=(b[j]-'0');
        // 两位数字相减，结果要么是一位正数，要么是一位负数
        // 当结果 t>=0 时，当前位的计算结果就是t；当结果 t<0 时，需要向高位借 1，也就是当前的结算结果需要加上 10。综合起来，当前位的计算结果为 (t+10)%10
        res.push_back((t+10)%10+'0');
        // 处理当前位的借位：t>=0 不需要借位，令 t=0；t<0 需要借位，令t=1。
        if(t>=0)t=0;
        else t=1;
    }
    // 处理前导0，由于低位的运算结果存储在 res 的前面，高位的前导0存储在 res 后面，因此需要进行删除。同时结果 0 就不需要删除了。
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // 翻转 res，得到从高位到低位的正确数字
    reverse(res.begin(),res.end());
    return res;
}

// 比较数字 a b 的大小
bool cmp(const string& a,const string& b)
{
    // 两个数字的位数不同，位数多的数值大
    if(a.size()!=b.size())return a.size()>b.size();
    // 两个数字的位数相同，从高位到低位开始比较
    for(int i=0,n=a.size();i<n;++i)
        if(a[i]!=b[i])return a[i]>b[i];
    // 数值 a b 相等，返回 true
    return true;
}

// 高精度 * 低精度：A * b
string mul(const string& A, const int b)
{
    string res;
    // t 表示进位
    for(int i=A.size()-1,t=0;i>=0||t;i--)
    {
        // 获得当前位的乘积和
        if(i>=0)t+=(A[i]-'0')*b;
        // 获取个位数字
        res.push_back((t%10)+'0');
        // 保留进位
        t/=10;
    }
    // 删除高位的前导 0，即字符串末尾的前导 0，如：1234 * 0 = 0000，需要将多余的 0 删掉
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // 由于之前计算得到的数字是低位存储在字符串前面的，所以需要翻转将高位数字存储在字符串的前面
    reverse(res.begin(),res.end());
    return res;
}

// 高精度 * 高精度：A * B，模拟传统的乘法运算
string mul(const string& A,const string& B)
{
    // 特判一下
    if(A=="0"||B=="0")return "0";
    string res="0";
    int m=A.size(),n=B.size();
    // 将 B 从低位到高位与整体被乘数 A 做乘法，将每次得到结果利用高精度加法进行累加即可  
    for(int i=n-1;i>=0;i--)
    {
        // 当前位为 0，就不要进行计算了
        if(B[i]=='0')continue;
        // 当前位 B[i] 与 A 相乘的结果
        string cur;
        // 在当前位 B[i] 的后面补 0，来表示当前位对应的10进制数字。即[i+1,n-1]之间要补0。
        // 采用小端存储，低位数字 0 存储在字符串的前面
        for(int j=n-1;j>i;j--)cur.push_back('0');
        // 将当前位 B[i]与 A 的计算结果倒序存储在 cur 中，即低位存储在字符串的前面
        // t 表示乘法进位，乘法进位为 0~9 的个位数字
        int x=B[i]-'0';
        for(int j=m-1,t=0;j>=0||t;j--)
        {
            if(j>=0)t+=(A[j]-'0')*x;
            // 添加个位数字
            cur.push_back((t%10)+'0');
            // 保留进位
            t/=10;
        }
        // 翻转 cur，将高位存储在字符串的前面，这样就是计算结果的正确表示了
        reverse(cur.begin(),cur.end());
        // 将当前位的结果进行累加
        res=add(res,cur);
    }
    return res;
}

// 高精度 * 高精度：A * B，采用竖式乘法
string mul2(const string& A,const string& B)
{
    // 特判一下
    if(A=="0"||B=="0")return "0";
    int n=A.size(),m=B.size();
    // n 位数字与 m 位数字相乘的结果最多有 n+m 位
    string res(m+n,'0');
    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--)
        {
            // A[i]*B[j] 的结果位于 res[i+j+1]，若 A[i]*B[j] >=10 的话，进位需要加到 res[i+j] 上
            // 计算当前位相乘的计算结果，同时加上一次的进位 res[i+j+1]
            int t=(A[i]-'0')*(B[j]-'0')+(res[i+j+1]-'0');
            // 更新当前位的个位数字
            res[i+j+1]=(t%10)+'0';
            // 保留进位。res[i+j]上的数字可以为任意数字，超过个位数字也是正确的
            res[i+j]+=t/10;
        }
    // 去除前导 0
    for(int i=0;i<m+n;++i)
        if(res[i]!='0')return res.substr(i);
    return "0";
}

// 高精度 / 低精度：A / b = c mod r
string div(const string &A,const int b,int& r)
{
    string res;
    // r表示余数
    r=0;
    // 除法是从高位到低位开始进行计算的
    for(int i=0,n=A.size();i<n;++i)
    {
        // 当前位的被除数
        r=r*10+(A[i]-'0');
        // 将商添加到 res 中
        res.push_back((r/b)+'0');
        // 保留余数
        r%=b;
    }
    // 商是高位存在在数组的前面，低位存储在数组的后面，所以只用处理前导 0 即可
    for(int i=0;i<res.size();++i)
        if(res[i]!='0')return res.substr(i);
    return "0";
}

// 高精度 / 高精度：A / B =  C mod r，模拟除法
// 模拟除法，每次取与 B 等长度的 A[i-m+1...i]进行运算
string div(const string& A,const string& B,string& r)
{
    // 被除数为 0，则商为 0，余数也为 0
    r="0";
    if(A=="0")return "0";
    string res;
    for(int i=0,n=A.size();i<n;++i)
    {
        // 添加低位数字
        r.push_back(A[i]);
        // 通过翻转来去除前导0
        reverse(r.begin(),r.end());
        while(r.size()&&r.back()=='0')r.pop_back();
        // 还原数字
        reverse(r.begin(),r.end());
        // 当前余数可以做减法，优先从减法次数最多的 9 开始做减法，加快减法速度
        if(cmp(r,B))
        {
            for(int j=9;j;j--)
            {
                // r-B*j>=0，则更新余数为 r-B*j ，商为 j
                if(cmp(r,mul(B,j)))
                {
                    r=sub(r,mul(B,j)),res.push_back(j+'0');
                    break;
                }
            }
        }
        // 不能做减法，商 0
        else res.push_back('0');
    }
    // 商是高位存在在数组的前面，低位存储在数组的后面，所以只用处理前导 0 即可
    reverse(res.begin(),res.end());
    // 删除后面的前导 0
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // 还原数字
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string A,B,r;
    cin>>A>>B;
    cout<<div(A,B,r)<<endl;
    cout<<r<<endl;
    return 0;
}