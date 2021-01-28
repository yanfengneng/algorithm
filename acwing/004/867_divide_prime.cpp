#include <iostream>
using namespace std;

void divide(int n)
{
    for(int i=2;i<=n/i;++i)
        // 当枚举到i的时候，就表明我们把2~i-1之间的所有质因子除干净了
        // 这里的i一定为质因子，把n里面的i除干净
        if(n%i==0)
        {
            int s=0;
            // 统计i个数字
            while(n%i==0)
            {
                s++;
                n/=i;
            }
            printf("%d %d\n",i,s);
        }
    // n中最多只会包含一个大于sqrt(n)的质因子，若有两个大于sqrt(n)的质因子，那么二者之积会大于n，矛盾
    // 一般的除到最后n会为1的，因为1既不是合数也不是质数，若最后n>1，表示就是那个大于sqrt(n)的质因子了
    if(n>1)printf("%d %d\n",n,1);
    puts("");
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        divide(x);
    }
    return 0;
}