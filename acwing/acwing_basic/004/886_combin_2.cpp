#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, mod = 1e9+7;
// fact[i]��ʾi�Ľ׳ˣ�infact[i]��ʾi�Ľ׳˵���Ԫ
// a/b (mod p)  �� a * b^(p-2) (mod p)��Ҳ����˵ b ��ģ m �ĳ˷���ԪΪ b^(m-2) (mod p)������ʹ�ÿ�����������Ԫ����Ϊ���� b^(m-2)
int fact[N],infact[N];

// �������� a^b (mod p)
// ��ν�����ݵĿ������ڽ�ָ��b�ֽ���˶���������ʾ��b= xk ... x1 x0��������ʵ�ֵĺ������Ƿ���ƽ��
// a^b = a^(2^xk+...2^x1+2^x0) = a^(2^xk) * ... * a^(2^x1) * a^(2^x0)�������Ͱ�a^b�ֽ��logb��������ˣ��������������к�һ����ǰһ���ƽ��
int qmi(int a,int b,int p)
{
    int res=1%p;
    while(b)
    {
        // ��ʼȡb����������ĩβ����Ϊ1����res��Ҫ������һ��
        // ���������ж�b�Ķ�����ĩβ�Ƿ�Ϊ1������Ϊa��ָ�����Ǵ�a��ʼ��
        if(b&1)res=1LL*res*a%p;
        // Ȼ���Ƴ��������������һλ���֣������´�ö��
        b>>=1;
        // Ȼ�󽫵�ǰa��ָ���ݽ���ƽ�����õ���һ���a��ָ����
        a=1LL*a*a%p;
    }
    return res;
}

// ��ʼ���׳������Ѿ��׳��������Ԫ
void init()
{
    // 0 �Ľ׳�Ϊ 1���Լ� 1 ����Ԫ����Ϊ 1
    fact[0]=infact[0]=1;
    // �� i �Ľ׳��Լ� i �Ľ׳˵���Ԫ
    for(int i=1;i<N;++i){
        fact[i]=1LL*fact[i-1]*i%mod;
        // i ����Ԫ���� i^(mod-2) 
        infact[i]=1LL*infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
}

int main()
{
    init();
    int n;scanf("%d",&n);
    while(n--)
    {
        int a,b;scanf("%d%d",&a,&b);
        // c[a][b]=a!/(b!*(a-b)!) ������Ԫ������ת��Ϊ�˷����õ�fact[a]*infact[b]*infact[a-b]
        printf("%d\n",1LL*fact[a]*infact[a-b]%mod*infact[b]%mod);
    }
    return 0;
}