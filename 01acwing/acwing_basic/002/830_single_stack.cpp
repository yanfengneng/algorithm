#include <iostream>
using namespace std;

const int N = 1e5+10;
// �±�0��ʾջ��
int stk[N],tt=0;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        // stk[tt]>=ai����ôi����߱�iС�������϶�����ǰ�棬���е�ջ
        while(tt&&stk[tt]>=x)tt--;
        // ֮ǰ����ջ��Ԫ�ض���ai�󣬿϶������Ǵ𰸵�
        if(tt)printf("%d ",stk[tt]);
        else printf("-1 ");

        // ����ջ��Ԫ�� < ai�ˣ����Խ�����ջ��
        stk[++tt]=x;
    }
    return 0;
}