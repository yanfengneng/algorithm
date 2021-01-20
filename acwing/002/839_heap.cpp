#include <iostream>
#include <cstring>
using namespace std;

// �������һ��С����
const int N = 1e5+10;

// ph[j]=k�ǵ�j������ĵ����ڶ��е��±�Ϊk��hp[k]=j��ʾ�����±�Ϊk�ĵ��ǵ�j������ĵ�
int h[N],ph[N],hp[N],len=0;

void heap_swap(int a,int b)
{
    // �����˴˵��±�
    swap(ph[hp[a]],ph[hp[b]]);
    // �����˴˵ĵ�x�β��
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

// �ڵ�u�³�
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

// �ڵ�u�ϸ�
void up(int u)
{
    // �����ڵ��ֵ���ں��ӽڵ�ֵ�������swap
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
            // ֻ����һ��ִ��
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