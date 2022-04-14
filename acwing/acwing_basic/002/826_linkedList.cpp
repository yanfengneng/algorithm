#include <iostream>

using namespace std;
const int N = 1e5+10;

// head �ڵ��ʾͷ�ڵ���±꣬e[i]��ʾ�ڵ�i��ֵ��ne[i]��ʾ�ڵ�i��nextָ��ֵ��idx��ʾ��ǰ�Ѿ��õ����ĸ���
int head,e[N],ne[N],idx;

// ��ʼ��
void init()
{
    head=-1;// -1 ��ʾ�ռ�
    idx=0;// ��ʾ���ǿ��Դ�0�ŵ㿪ʼ���䣬��Ϊÿһ���㶼û��ʹ��
}

// ��x�嵽ͷ�ڵ�
void add_to_head(int x)
{  
    // ��x��ֵ����ָ��idx��idx��nextָ��ָ��headָ���λ�ã�head�ڵ�ָ��idx��idx�ƶ�����һ��λ��
    e[idx]=x,ne[idx]=head,head=idx,idx++;
}

// ��x���뵽�±�Ϊk�ĵ����
void add(int k,int x)
{
    // �ְ�x��ֵ��������idx��nextָ��ָ��
    e[idx]=x,ne[idx]=ne[k],ne[k]=idx,idx++;
}

// ���±�Ϊk�ĵ����ĵ�ɾ��
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