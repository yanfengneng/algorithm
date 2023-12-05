#include <iostream>
using namespace std;

const int N = 1e5+10;
// 下标0表示栈空
int stk[N],tt=0;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        // stk[tt]>=ai，那么i的左边比i小的数，肯定还在前面，进行弹栈
        while(tt&&stk[tt]>=x)tt--;
        // 之前弹出栈的元素都比ai大，肯定不会是答案的
        if(tt)printf("%d ",stk[tt]);
        else printf("-1 ");

        // 现在栈顶元素 < ai了，可以进行入栈了
        stk[++tt]=x;
    }
    return 0;
}