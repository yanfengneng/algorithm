#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int primes[N],cnt=0;
// v[i] ��¼���� i Ϊ�������Ǻ�����v[i]=trueʱ i Ϊ���������� i Ϊ����
bool v[N];
// sum[i]=c ��ʾ���� i �ĸ���Ϊ c
int sum[N];

// ����ɸ��
void get_primes(int n)
{
    for(int i=2;i<=n;++i)
    {
        // iΪ�����������primes��
        if(!v[i])primes[cnt++]=i;
        // ����ǰ��i����һ��������pj
        for(int j=0;primes[j]<=n/i;++j)
        {
            v[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

// ���� n ���溬������ p �ĸ���������ļ����ǲ��ز�©�ġ�
// p^k�ı����ᱻ����k�Σ���һ����p�ı���ʱ������һ�Σ��ڶ�����p^2�ı���ʱ������һ�Σ���������p^3�ı���ʱ������һ��...��k����p^k�ı���ʱ������һ�Ρ��ܹ�������k�Σ��ǲ��ز�©�ġ�
int get(int n,int p)
{
    int res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

// A * b���� b ����һ�����壬Ȼ���� A ��ÿһλ��ˣ�A�е����ֲ���С�˴洢������λ���ִ洢�������ǰ�棬��λ���ִ洢������ĺ���
vector<int> mul(const vector<int>& A,const int b)
{
    if(b==0)return {0};
    vector<int> res;
    // t ��ʾ�˷���λ������Ľ�λ������0 1������Ϊ��������
    for(int i=0,t=0,n=A.size();i<n||t>0;++i)
    {
        // ��õ�ǰλ�ĳ˻���
        if(i<n)t+=A[i]*b;
        // ��Ӹ�λ����
        res.push_back(t%10);
        // ������λ
        t/=10;
    }

     // �� 1234 * 0 = 0000����Ҫɾ��ǰ��0
    while(res.size()>1&&res.back()==0)res.pop_back();
    return res;
}

int main()
{
    int a,b;cin>>a>>b;

    // �� a �ֽ�������
    get_primes(a);

    for(int i=0;i<cnt;++i)
    {
        // ��ǰ������Ϊ p
        int p=primes[i];
        // �÷������� p �ĸ�����ȥ��ĸ���� p �ĸ���������ļ���������Ĺ�ʽΪa!/(b!*(a-b)!)������� a ���� p �ĸ�����ȥ b ���� p �ĸ����� (a-b) ���� p �ĸ�����
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);
    }

    // ʹ�ø߾��ȳ˷������������ӳ˵�һ��ȥ�ͺ���
    vector<int> res={1};
    for(int i=0;i<cnt;++i)
        // res*p^k��������k��p��ˣ�����k*p��������Ҫʹ��һ��ѭ��
        for(int j=0;j<sum[i];++j)
            res=mul(res,primes[i]);
    
    // �����ӡ res ���ɣ����ڲ���С�˴洢�����Ը�λ�ں󣬴Ӻ���ǰ��ӡ����
    for(int i=res.size()-1;i>=0;i--)printf("%d",res[i]);
    return 0;
}