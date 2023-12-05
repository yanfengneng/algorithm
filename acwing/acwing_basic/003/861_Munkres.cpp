#include <iostream>
#include <cstring>
using namespace std;

int n1,n2,m;

const int N = 510, M =1e5+10;

// �ڽӱ���ϡ��ͼ
int h[N],e[M],ne[M],idx=0;
// match[y]=x��ʾy�����ӵ�������Ϊx������
int match[N];
// ��ʱԤ�����飬flag[y]=x��ʾ����y������xԤ����
bool flag[N];

void add(int a,int b)
{
    // ͷ�巨
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x)// �ж�x�������Ƿ���ƥ�䵽����
{
    // ��������xϲ��������
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        // ������ƥ���У�����j��û�б�Ԥ��
        if(!flag[j])
        {
            // ���j�����ӱ�Ԥ����
            flag[j]=true;
            // ��j�����ӵ����j�����ӵ������ѿ��Ի���һ���Լ�ϲ�������ӣ���x������ƥ��ɹ�
            if(!match[j]||find(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    }
    // �Լ�ϲ�������Ӷ����������ˣ�ƥ��ʧ��
    return false;
}

int main()
{
    scanf("%d%d%d",&n1,&n2,&m);

    // ��ʼ���ڽӱ�������
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        // ֻ����ߵĵ�ָ���ұ߼���
        add(a,b);
    }

    int res=0;
    for(int i=1;i<=n1;++i)
    {
        // ÿ�������Ӷ�Ҫ��Ԥ����գ�����������б�̥�������ҵ��¼ң���i�������ѵ�
        memset(flag,0,sizeof flag);
        // i�������Ƿ�ƥ�䵽����
        if(find(i))res++;
    }

    printf("%d\n",res);

    return 0;
}