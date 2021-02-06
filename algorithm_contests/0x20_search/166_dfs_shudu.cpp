#include <iostream>
#include <algorithm>
using namespace std;

const int N = 9;
// ones存的是[0,8]范围内的数，有几个1；m存的是每二进制数对应第几位数（下标从0开始），比如1000对应3
int ones[1<<N],m[1<<N];

int row[N],col[N],cell[3][3];
char str[100];

inline int lowbit(int x)
{
    return x&-x;
}

void init()
{
    for(int i=0;i<N)
}
int main()
{
    for(int i=0;i<N;++i)m[1<<i]=i;

    for(int i=0;i<1<<N;i++)
    {
        int s=0;
        for(int j=i;j;j-=lowbit(j))s++;
        ones[i]=s;// i的二进制表示中有s个1
    }

    while(cin>>str,str[0]!='e')
    {
        init();
    }
}