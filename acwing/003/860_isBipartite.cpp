#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10,M =2e5+10;

// �ڽӱ�洢ͼ��e������ڽڵ�ı�š�ne�����nextָ�룬����һ���ڵ�ı�š�idx��ʾ��ǰ��ʹ�õĽڵ��š�
int h[N],e[M],ne[M],idx=0;
// ����i����ɫ
int color[N];
int n,m;

void add(int a,int b)
{
    // ͷ�巨
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)
{
    // ���޸���ɫ
    color[u]=c;

    // �� u ���ڽڵ����Ⱦɫ
    for(int i=h[u];i!=-1;i=ne[i])
    {   
        int j=e[i];
        
        // �� j �ŵ�û�б�Ⱦɫ�Ļ�����Ⱦ����һ����ɫ
        if(!color[j])
        {
            // ���ڸ������򷵻�false
            if(!dfs(j,3-c))return false;
        }
        // �ڽڵ㱻Ⱦ����ͬ����ɫ��ì����
        else if(color[j]==c)return false;
    }

    return true;
}

int main()
{
    // ��ʼ���ڽӱ�������
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);

    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        // ����ͼ����������������
        add(a,b),add(b,a);
    }

    bool flag=true;
    for(int i=1;i<=n;++i)
    {
        // ���i�ŵ�û�б�Ⱦɫ���Ͱ���Ⱦ��1��ɫ
        if(!color[i])
        {
            // ���ûȾ�ɹ�������ڸ����������ܽ��ж���ƥ��
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
        }
    }

    if(flag)puts("Yes");
    else puts("No");

    return 0;
}