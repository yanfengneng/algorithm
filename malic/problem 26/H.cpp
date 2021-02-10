#include <iostream>
using namespace std;

int a[110];

int main()
{
    int x;
    // a[i] 表示存了数字 i
    while(scanf("%d",&x)&&x!=0)a[x]++;

    int res=0;
    // 因为是2到15个 1~99 的正整数，所以我们只用枚举[1,50]中的2倍了
    for(int i=1;i<=50;i++)
        if(a[i]&&a[i*2])res++;

    printf("%d\n",res);
    return 0;
}