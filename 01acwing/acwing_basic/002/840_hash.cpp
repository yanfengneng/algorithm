#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+3;

// hash函数的拉链法类比邻接表，也就是和邻接表一样的
// idx表示当前可以使用的节点编号，在数组表示的邻接表的单链表中，每个节点都有一个单独的编号，用idx表示
int h[N],e[N],ne[N],idx=0;

void insert(int x)
{
    // 在c++中，当x为负数时，取余的结果为负数，因此为了让取余的结果为正数，就必须使用如下取余方式
    // 只要被除数为负数，取模的结果就为负数，这是c++编译器规定的
    int k=(x%N+N)%N;
    
    // 头插法，新的节点编号为idx，然后新节点的next指针指向头节点指向的位置（节点编号），然后让头节点指向新的节点编号
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x)
{
    int k=(x%N+N)%N;
    // -1表示空节点编号
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i]==x)return true;
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    while(n--)
    {
        char op[2];
        int x;
        // %s字符串格式会以空格或换行为读入结束标志的，不建议使用%c，避免%c读入空格或换行
        scanf("%s%d",op,&x);

        if(op[0]=='I')insert(x);
        else
        {
            if(find(x))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}