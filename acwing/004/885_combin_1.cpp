#include <iostream>
using namespace std;

// �� C++ �У�����Ĵ�С�����Ǳ���ʱ��֪�ĳ�������˱���Ҫ��const
const int N=2010,mod=1e9+7;
int c[N][N];
int a,b,n;

// �������
void init()
{
    // ��ס������ʽc[i][0]=1��c[i][j]=c[i-1][j-1]+c[i-1][j]
    for(int i=0;i<N;++i){
        for(int j=0;j<=i;++j){
            if(!j)c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}

int main()
{
    scanf("%d",&n);
    init();
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        printf("%d\n",c[a][b]);
    }
    return 0;
}