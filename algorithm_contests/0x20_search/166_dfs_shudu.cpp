#include <iostream>
#include <algorithm>
using namespace std;

const int N = 9;
// ones�����[0,8]��Χ�ڵ������м���1��m�����ÿ����������Ӧ�ڼ�λ�����±��0��ʼ��������1000��Ӧ3
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
        ones[i]=s;// i�Ķ����Ʊ�ʾ����s��1
    }

    while(cin>>str,str[0]!='e')
    {
        init();
    }
}