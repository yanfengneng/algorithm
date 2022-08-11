#include <bits/stdc++.h>
using namespace std;

// �߾��ȼӷ�
string add(const string& a,const string& b)
{
    string c;
    // ����������λ������ӵĽ�λ
    int t=0;
    // �ӵ�λ��ʼ���λ�������㣬��ӵĽ���Ǵӵ�λ����λ���д洢�ģ�������ս����Ҫ���з�ת�����ܳ�Ϊ��ȷ������
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t;i--,j--)
    {
        if(i>=0)t+=a[i]-'0';
        if(j>=0)t+=b[j]-'0';
        c.push_back('0'+(t%10));
        t/=10;
    }
    // ���ڵõ��Ľ���ǵ�λ�����ȱ��洢�ģ������Ҫ���з�ת���ܳ�Ϊ��ȷ���
    // �ӷ�������ָ�λ����ǰ�� 0 �����
    reverse(c.begin(),c.end());
    return c;
}

// �߾��ȼ�����ʹ�ô�����С��������һ��������ָ����������������λ��һ��������ֽ�λ������ģ������ٴ���һЩ�߽����⡣
// A>=0 B>=0 �� A>=B
string sub(const string& a,const string& b)
{
    // ����Ľ���Ǹ�λ�ȴ洢�� res �еģ�������ջ�Ҫ�� res ���з�ת
    string res;
    // t ��ʾ��λ
    int t=0;
    // �ӵ�λ����λ��ʼ����
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||t;i--,j--)
    {   
        // ��ǰλ�ļ�����Ϊ A[i]-B[i]-t
        if(i>=0)t=(a[i]-'0')-t;
        if(j>=0)t-=(b[j]-'0');
        // ��λ������������Ҫô��һλ������Ҫô��һλ����
        // ����� t>=0 ʱ����ǰλ�ļ���������t������� t<0 ʱ����Ҫ���λ�� 1��Ҳ���ǵ�ǰ�Ľ�������Ҫ���� 10���ۺ���������ǰλ�ļ�����Ϊ (t+10)%10
        res.push_back((t+10)%10+'0');
        // ����ǰλ�Ľ�λ��t>=0 ����Ҫ��λ���� t=0��t<0 ��Ҫ��λ����t=1��
        if(t>=0)t=0;
        else t=1;
    }
    // ����ǰ��0�����ڵ�λ���������洢�� res ��ǰ�棬��λ��ǰ��0�洢�� res ���棬�����Ҫ����ɾ����ͬʱ��� 0 �Ͳ���Ҫɾ���ˡ�
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // ��ת res���õ��Ӹ�λ����λ����ȷ����
    reverse(res.begin(),res.end());
    return res;
}

// �Ƚ����� a b �Ĵ�С
bool cmp(const string& a,const string& b)
{
    // �������ֵ�λ����ͬ��λ�������ֵ��
    if(a.size()!=b.size())return a.size()>b.size();
    // �������ֵ�λ����ͬ���Ӹ�λ����λ��ʼ�Ƚ�
    for(int i=0,n=a.size();i<n;++i)
        if(a[i]!=b[i])return a[i]>b[i];
    // ��ֵ a b ��ȣ����� true
    return true;
}

// �߾��� * �;��ȣ�A * b
string mul(const string& A, const int b)
{
    string res;
    // t ��ʾ��λ
    for(int i=A.size()-1,t=0;i>=0||t;i--)
    {
        // ��õ�ǰλ�ĳ˻���
        if(i>=0)t+=(A[i]-'0')*b;
        // ��ȡ��λ����
        res.push_back((t%10)+'0');
        // ������λ
        t/=10;
    }
    // ɾ����λ��ǰ�� 0�����ַ���ĩβ��ǰ�� 0���磺1234 * 0 = 0000����Ҫ������� 0 ɾ��
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // ����֮ǰ����õ��������ǵ�λ�洢���ַ���ǰ��ģ�������Ҫ��ת����λ���ִ洢���ַ�����ǰ��
    reverse(res.begin(),res.end());
    return res;
}

// �߾��� * �߾��ȣ�A * B��ģ�⴫ͳ�ĳ˷�����
string mul(const string& A,const string& B)
{
    // ����һ��
    if(A=="0"||B=="0")return "0";
    string res="0";
    int m=A.size(),n=B.size();
    // �� B �ӵ�λ����λ�����屻���� A ���˷�����ÿ�εõ�������ø߾��ȼӷ������ۼӼ���  
    for(int i=n-1;i>=0;i--)
    {
        // ��ǰλΪ 0���Ͳ�Ҫ���м�����
        if(B[i]=='0')continue;
        // ��ǰλ B[i] �� A ��˵Ľ��
        string cur;
        // �ڵ�ǰλ B[i] �ĺ��油 0������ʾ��ǰλ��Ӧ��10�������֡���[i+1,n-1]֮��Ҫ��0��
        // ����С�˴洢����λ���� 0 �洢���ַ�����ǰ��
        for(int j=n-1;j>i;j--)cur.push_back('0');
        // ����ǰλ B[i]�� A �ļ���������洢�� cur �У�����λ�洢���ַ�����ǰ��
        // t ��ʾ�˷���λ���˷���λΪ 0~9 �ĸ�λ����
        int x=B[i]-'0';
        for(int j=m-1,t=0;j>=0||t;j--)
        {
            if(j>=0)t+=(A[j]-'0')*x;
            // ��Ӹ�λ����
            cur.push_back((t%10)+'0');
            // ������λ
            t/=10;
        }
        // ��ת cur������λ�洢���ַ�����ǰ�棬�������Ǽ���������ȷ��ʾ��
        reverse(cur.begin(),cur.end());
        // ����ǰλ�Ľ�������ۼ�
        res=add(res,cur);
    }
    return res;
}

// �߾��� * �߾��ȣ�A * B��������ʽ�˷�
string mul2(const string& A,const string& B)
{
    // ����һ��
    if(A=="0"||B=="0")return "0";
    int n=A.size(),m=B.size();
    // n λ������ m λ������˵Ľ������� n+m λ
    string res(m+n,'0');
    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--)
        {
            // A[i]*B[j] �Ľ��λ�� res[i+j+1]���� A[i]*B[j] >=10 �Ļ�����λ��Ҫ�ӵ� res[i+j] ��
            // ���㵱ǰλ��˵ļ�������ͬʱ����һ�εĽ�λ res[i+j+1]
            int t=(A[i]-'0')*(B[j]-'0')+(res[i+j+1]-'0');
            // ���µ�ǰλ�ĸ�λ����
            res[i+j+1]=(t%10)+'0';
            // ������λ��res[i+j]�ϵ����ֿ���Ϊ�������֣�������λ����Ҳ����ȷ��
            res[i+j]+=t/10;
        }
    // ȥ��ǰ�� 0
    for(int i=0;i<m+n;++i)
        if(res[i]!='0')return res.substr(i);
    return "0";
}

// �߾��� / �;��ȣ�A / b = c mod r
string div(const string &A,const int b,int& r)
{
    string res;
    // r��ʾ����
    r=0;
    // �����ǴӸ�λ����λ��ʼ���м����
    for(int i=0,n=A.size();i<n;++i)
    {
        // ��ǰλ�ı�����
        r=r*10+(A[i]-'0');
        // ������ӵ� res ��
        res.push_back((r/b)+'0');
        // ��������
        r%=b;
    }
    // ���Ǹ�λ�����������ǰ�棬��λ�洢������ĺ��棬����ֻ�ô���ǰ�� 0 ����
    for(int i=0;i<res.size();++i)
        if(res[i]!='0')return res.substr(i);
    return "0";
}

// �߾��� / �߾��ȣ�A / B =  C mod r��ģ�����
// ģ�������ÿ��ȡ�� B �ȳ��ȵ� A[i-m+1...i]��������
string div(const string& A,const string& B,string& r)
{
    // ������Ϊ 0������Ϊ 0������ҲΪ 0
    r="0";
    if(A=="0")return "0";
    string res;
    for(int i=0,n=A.size();i<n;++i)
    {
        // ��ӵ�λ����
        r.push_back(A[i]);
        // ͨ����ת��ȥ��ǰ��0
        reverse(r.begin(),r.end());
        while(r.size()&&r.back()=='0')r.pop_back();
        // ��ԭ����
        reverse(r.begin(),r.end());
        // ��ǰ�������������������ȴӼ����������� 9 ��ʼ���������ӿ�����ٶ�
        if(cmp(r,B))
        {
            for(int j=9;j;j--)
            {
                // r-B*j>=0�����������Ϊ r-B*j ����Ϊ j
                if(cmp(r,mul(B,j)))
                {
                    r=sub(r,mul(B,j)),res.push_back(j+'0');
                    break;
                }
            }
        }
        // �������������� 0
        else res.push_back('0');
    }
    // ���Ǹ�λ�����������ǰ�棬��λ�洢������ĺ��棬����ֻ�ô���ǰ�� 0 ����
    reverse(res.begin(),res.end());
    // ɾ�������ǰ�� 0
    while(res.size()>1&&res.back()=='0')res.pop_back();
    // ��ԭ����
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