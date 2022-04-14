#include <iostream>
using namespace std;

// 在 C++ 中，数组的大小必须是编译时已知的常量，因此必须要用const
const int N=2010,mod=1e9+7;
int c[N][N];
int a,b,n;

// 求组合数
void init()
{
    // 记住两个公式c[i][0]=1；c[i][j]=c[i-1][j-1]+c[i-1][j]
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