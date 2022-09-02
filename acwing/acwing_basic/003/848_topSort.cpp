#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int N = 1e5+10;

// �ڽӱ�idx��ʾ��ǰ����ʹ�õĽڵ���
int h[N],e[N],ne[N],idx=0;

// qΪ���У�dΪ��¼�������ȵ�����
int q[N],d[N];

// �����ab
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topSort()
{
    // hhΪ��ͷ��ttΪ��β
    int hh=0,tt=-1;

    // �����Ϊ 0 �ĵ�������
    for(int i=1;i<=n;++i)
        if(!d[i])q[++tt]=i;

    // ��ʼbfs
    while(hh<=tt)
    {
        // ��ö�ͷԪ�ز�����ͷԪ�س���
        int t=q[hh++];

        // ɾ��t�����������ڽӱ�
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            // ���� j ����ȼ� 1
            d[j]--;
            // ����ȼ�Ϊ0�ˣ���������
            if(!d[j])q[++tt]=j;
        }
    }
    // tt����n-1�Ļ�����ʾ�����Ѿ�����n�������ˣ���ʾ����һ�������޻�ͼ������Ͳ����޻�ͼ
    // ������ڻ��Ļ������������еĶ��������ȻС��n����˻��и������ȱض���Ϊ1����ô���޷����ж��У�Ҳ���޷��洢�����������С�������������������Ԫ��С��n����Ȼ���ڻ���
    return tt==n-1;
}

int main()
{
    scanf("%d%d",&n,&m);
    // ��ʼ���ڽӱ��������
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        // ����b�����+1
        d[b]++;
    }

    if(topSort())
    {
        // ���ڶ��в��������������е�Ԫ�س����ˣ����Զ����б���Ĵ���Ϊtop���У�����ֻ��Ҫ������ӡ�����ͺ���
        for(int i=0;i<n;++i)printf("%d ",q[i]);
        puts("");
    }
    else puts("-1");
    return 0;
}