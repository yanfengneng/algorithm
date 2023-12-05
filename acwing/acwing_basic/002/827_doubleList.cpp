#include <iostream>
#include <string>
using namespace std;

const int N = 1e5+10;

// e[i]表示i节点的值；l[i]表示i节点的prev指针；r[i]表示i节点的next指针；idx当前可以使用的节点下标
int e[N],l[N],r[N],idx;

// 初始化
void init()
{
    // 0表示左端点，1表示右端点
    r[0]=1,l[1]=0;
    // 0和1已经被使用过了，现在从2号点开始用
    idx=2;
}

// 在下标为k的右边插入一个点x
void add(int k,int x)
{
    // 把x的值赋给指针idx；idx的节点左右指针连上；将k的右节点的左指针指向idx；将k的右指针脸上idx；idx++
    e[idx]=x,r[idx]=r[k],l[idx]=k,l[r[k]]=idx,r[k]=idx,idx++;
}

// 删除下标为k的节点
void remove(int k)
{
    // 结合画图理解一下
    r[l[k]]=r[k],l[r[k]]=l[k];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin>>m;
    init();

    while(m--)
    {
        string op;
        cin>>op;
        int k,x;
        if(op=="L")
        {
            cin>>x;
            add(0,x);
        }
        else if(op=="R")
        {
            cin>>x;
            // 在尾节点的左边插入，也就是在链表最右端插入
            add(l[1],x);
        }
        else if(op=="D")
        {
            cin>>k;
            // 第k个点对应下标为k+1
            remove(k+1);
        }
        else if(op=="IL")
        {
            cin>>k>>x;
            // 在下标k+1的左边插入点，即在l[k+1]的右边插入
            add(l[k+1],x);
        }
        else 
        {
            cin>>k>>x;
            // 在第k个点有点插入
            add(k+1,x);
        }
    }

    for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}