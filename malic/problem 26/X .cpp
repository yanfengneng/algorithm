#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int c[10];
        for(int i=0;i<10;i++)cin>>c[i];

        bool flag=true;
        // 用 a 来记录组A的栈顶元素，用 b 来记录组B的栈顶元素
        // 输入的元素没有 a b 大的话，表示构不成合法的输入了
        int a=-1,b=-1;
        for(int i=0;i<10;++i)
        {
            if(c[i]>a)a=c[i];
            else if(c[i]>b)b=c[i];
            else flag=false;
        }

        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}