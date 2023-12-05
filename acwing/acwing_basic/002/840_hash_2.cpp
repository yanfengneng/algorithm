#include <iostream>
#include <cstring>
using namespace std;

// 开放地址法，用0x3f3f3f3f来表示不在hash表中的数
const int N = 2e5+3,Max=0x3f3f3f3f;
int h[N];

int find(int x)
{
    int k=(x%N+N)%N;

    // 寻找插入的位置
    while(h[k]!=Max&&h[k]!=x)
    {
        ++k;
        if(k==N)k=0;
    }

    // k要是寻找到的位置，要么是应该插入的空位置
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h,0x3f,sizeof h);
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        // 查找到x的位置
        int k=find(x);

        // 若是插入，则k是插入的位置
        if(op[0]=='I')h[k]=x;
        // 若是查找，则k是查找的位置，然后判断该位置的数是否在数据范围内
        else
        {
            if(h[k]!=Max)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}