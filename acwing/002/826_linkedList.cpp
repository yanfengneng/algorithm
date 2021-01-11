#include <iostream>

using namespace std;
const int N = 1e5+10;

// head 节点表示头节点的下标，e[i]表示节点i的值，ne[i]表示节点i的next指针值，idx表示当前已经用到了哪个点
int head,e[N],ne[N],idx;

// 初始化
void init()
{
    head=-1;// -1 表示空集
    idx=0;// 表示我们可以从0号点开始分配，因为每一个点都没有使用
}

// 将x插到头节点
void add_to_head(int x)
{  
    // 把x的值赋给指针idx；idx的next指针指向head指向的位置；head节点指向idx；idx移动到下一个位置
    e[idx]=x,ne[idx]=head,head=idx,idx++;
}

// 把x插入到下标为k的点后面
void add(int k,int x)
{
    // 现把x的值存下来；idx的next指针指向
    e[idx]=x,ne[idx]=ne[k],ne[k]=idx,idx++;
}

// 将下标为k的点后面的点删掉
void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
    int m;
    scanf("%d",&m);
    init();
    while(m--)
    {
        char op;
        int k,x;
        getchar();
        scanf("%c",&op);
        //cin>>op;
        if(op=='H')
        {
            scanf("%d",&x);
            add_to_head(x);
        }
        else if(op=='D')
        {
            scanf("%d",&k);
            if(k==0)head=ne[head];
            else remove(k-1);
        }
        else
        {
            scanf("%d%d",&k,&x);
            add(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i])printf("%d ",e[i]);
    printf("\n");
    return 0;
}