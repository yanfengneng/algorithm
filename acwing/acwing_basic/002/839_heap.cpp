#include <iostream>
#include <cstring>
using namespace std;

// 构造的是一个小根堆
const int N = 1e5+10;

// ph[j]=k是第j个插入的点是在堆中的下标为k，hp[k]=j表示堆中下标为k的点是第j个插入的点
int h[N],ph[N],hp[N],len=0;

void heap_swap(int a,int b)
{
    // 交换彼此的下标
    swap(ph[hp[a]],ph[hp[b]]);
    // 交换彼此的第x次查出
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

// 节点u下沉
void down(int u)
{
    int t=u;
    if(2*u<=len&&h[2*u]<h[t])t=2*u;
    if(2*u+1<=len&&h[2*u+1]<h[t])t=2*u+1;
    if(t!=u)
    {
        heap_swap(u,t);
        down(t);
    }
}

// 节点u上浮
void up(int u)
{
    // 若父节点的值大于孩子节点值，则进行swap
     while(u/2&&h[u/2]>h[u])
     {
         heap_swap(u/2,u);
         u/=2;
     }
}

int main()
{
    int n,m=0;
    scanf("%d",&n);
    while(n--)
    {
        char op[5];
        int k,x;
        
        scanf("%s",op);
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            len++;
            m++;
            ph[m]=len,hp[len]=m;
            h[len]=x;
            up(len);
        }
        else if(!strcmp(op,"PM"))printf("%d\n",h[1]);
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,len);
            len--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,len);
            len--;
            // 只会有一个执行
            down(k),up(k);
        }
        else
        {
            scanf("%d%d",&k,&x);
            k=ph[k],h[k]=x;
            down(k),up(k);
        }
    }
    return 0;
}