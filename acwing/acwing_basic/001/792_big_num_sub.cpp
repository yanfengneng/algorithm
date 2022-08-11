#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �ж��Ƿ��� A >= B
bool cmp(vector<int>& A,vector<int>& B)
{
    // ��������λ����ͬ��λ��Խ�����ֵ��Խ��
    if(A.size()!=B.size())return A.size()>B.size();
    // λ����ͬ�Ļ����ʹӸ�λ����λ��ʼ�Ƚϡ�������ֵ��С�˴洢����λ�����ں���˴Ӻ���ǰ�ȽϱȽ�
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=B[i])return A[i]>B[i];
    // A B��ȣ�����true
    return true;
}

// A>=0 B>=0 A>=B
vector<int> sub(vector<int>& A,vector<int>& B)
{
    vector<int> res;
    // t��ʾ��λ�������˸�λ��t=1����û�н��λ��t=0��
    int t=0;
    // ���ڹ涨��A>=B������A��λ�����ڵ���B��λ����ÿ����Ҫ�ж��±�i�Ƿ񳬹�B�Ĵ�С����
    for(int i=0,n=A.size(),m=B.size();i<n;++i)
    {
        // ��ǰλ�ļ���ֵΪ c = A[i]-B[i]-t���� c >=0����ǰλ����Ҫ��λ��λ����t=0���ɣ��� c<0����ǰλ��Ҫ���λ��1����t=1����
        t=A[i]-t;
        // û������ֵ B �ķ�Χ����������
        if(i<m)t-=B[i];
        // ��λ������������Ҫô��һλ������Ҫô��һλ����
        // ����� t>=0 ʱ����ǰλ�ļ���������t������� t<0 ʱ����Ҫ���λ�� 1��Ҳ���ǵ�ǰ�Ľ�������Ҫ���� 10���ۺ���������ǰλ�ļ�����Ϊ (t+10)%10
        res.push_back((t+10)%10);
        // ����ǰλ�Ľ�λ��t>=0 ����Ҫ��λ���� t=0��t<0 ��Ҫ��λ����t=1��
        if(t>=0)t=0;
        else t=1;
    }
    // ����Ľ���ǵ�λ���ִ洢�� res ��ǰ�棬��˸�λ���ֵõ�ǰ��0�洢��������棬��Ҫ����ɾ��
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    string a,b;
    vector<int> A,B;

    cin>>a>>b;// a = "123456"
    // ���������λ(���ֵλ)�Ǵ��������β���ģ���λ(���λ)�Ǵ��������ǰ���
    // ���ǰѸ�λ���ִ����������ǰ�棬���ֵ���ִ������������棬���ڽ�λ
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