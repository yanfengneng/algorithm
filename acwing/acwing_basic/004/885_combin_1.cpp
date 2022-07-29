#include <iostream>
using namespace std;

// 在 C++ 中，数组的大小必须是编译时已知的常量，因此必须要用const
const int N=2010,mod=1e9+7;
int c[N][N];

// 求组合数
void init()
{
    // 两个公式：c[a][0]=1 表示从 a 个数中选 0 个数的方案数为 1 种；
    // c[a][b]=c[a-1][b-1]+c[a-1][b] 从 a 个数中取 b 个数，分为两种情况：1）取第 b 号数，那么从剩下的 a-1 个数中取 b-1 个数即可，即为c[a-1][b-1]；2）不取第 b 号数，那么从剩下的 a-1 个数中继续取 b 个数即可，即为c[a-1][b]
    // 这里的 a b 都是从小到大进行枚举的，是因为计算 c[a][b] 时会用到之前计算过的 c[a-1][b-1] c[a-1][b]
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