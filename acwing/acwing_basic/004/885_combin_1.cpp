#include <iostream>
using namespace std;

// �� C++ �У�����Ĵ�С�����Ǳ���ʱ��֪�ĳ�������˱���Ҫ��const
const int N=2010,mod=1e9+7;
int c[N][N];

// �������
void init()
{
    // ������ʽ��c[a][0]=1 ��ʾ�� a ������ѡ 0 �����ķ�����Ϊ 1 �֣�
    // c[a][b]=c[a-1][b-1]+c[a-1][b] �� a ������ȡ b ��������Ϊ���������1��ȡ�� b ��������ô��ʣ�µ� a-1 ������ȡ b-1 �������ɣ���Ϊc[a-1][b-1]��2����ȡ�� b ��������ô��ʣ�µ� a-1 �����м���ȡ b �������ɣ���Ϊc[a-1][b]
    // ����� a b ���Ǵ�С�������ö�ٵģ�����Ϊ���� c[a][b] ʱ���õ�֮ǰ������� c[a-1][b-1] c[a-1][b]
    for(int a=0;a<N;++a)
        for(int b=0;b<=a;++b)
            if(b==0)c[a][0]=1;
            else c[a][b]=(c[a-1][b-1]+c[a-1][b])%mod;
}

int main()
{
    int n;scanf("%d",&n);
    init();
    for(int i=0;i<n;++i){
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",c[a][b]);
    }
    return 0;
}