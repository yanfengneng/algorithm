#include <iostream>
#include <string>
using namespace std;

const int N = 1e5+10;

// e[i]��ʾi�ڵ��ֵ��l[i]��ʾi�ڵ��prevָ�룻r[i]��ʾi�ڵ��nextָ�룻idx��ǰ����ʹ�õĽڵ��±�
int e[N],l[N],r[N],idx;

// ��ʼ��
void init()
{
    // 0��ʾ��˵㣬1��ʾ�Ҷ˵�
    r[0]=1,l[1]=0;
    // 0��1�Ѿ���ʹ�ù��ˣ����ڴ�2�ŵ㿪ʼ��
    idx=2;
}

// ���±�Ϊk���ұ߲���һ����x
void add(int k,int x)
{
    // ��x��ֵ����ָ��idx��idx�Ľڵ�����ָ�����ϣ���k���ҽڵ����ָ��ָ��idx����k����ָ������idx��idx++
    e[idx]=x,r[idx]=r[k],l[idx]=k,l[r[k]]=idx,r[k]=idx,idx++;
}

// ɾ���±�Ϊk�Ľڵ�
void remove(int k)
{
    // ��ϻ�ͼ���һ��
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
            // ��β�ڵ����߲��룬Ҳ�������������Ҷ˲���
            add(l[1],x);
        }
        else if(op=="D")
        {
            cin>>k;
            // ��k�����Ӧ�±�Ϊk+1
            remove(k+1);
        }
        else if(op=="IL")
        {
            cin>>k>>x;
            // ���±�k+1����߲���㣬����l[k+1]���ұ߲���
            add(l[k+1],x);
        }
        else 
        {
            cin>>k>>x;
            // �ڵ�k�����е����
            add(k+1,x);
        }
    }

    for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}