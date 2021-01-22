#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10,M = 2*N;
int n;
// idx��ʾÿ���ڵ��Ӧһ��Ψһ�ı�ţ�����ǰ����ʹ�õĽڵ���
int h[N],e[M],ne[M],idx=0;
// ��Ƕ���ʹ�ù�û��
bool flag[N]={0};

// ��¼ȫ�ֵĴ�
int ans=N;

// ���ӱ�a->b
void add(int a,int b)
{
    // ͷ�巨��idxΪ�½ڵ�ı��
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

// ��uΪ���������е������
int dfs(int u)
{
    // ��ǵ�u�Ѿ����ѹ���
    flag[u]=true;

    // sum��uΪ��Ҳ��һ���㣬res���������ɾ��֮��ÿ����ͨ���С�����ֵ
    int sum=1,res=0;

    // ����u���ڽڵ�
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!flag[j])
        {
            // ��s����ʾ��ǰ��������Ĵ�С����ǰ�������Ҳ������ͨ��
            int s=dfs(j);
            // ��ǰ����Ҳ��һ����ͨ��
            res=max(res,s);
            // ��ǰ���������Ҳ��ڵ�iΪ��������һ����
            sum+=s;
        }
    }
    // n-sumΪ��������һ�磬ȡ��max��resΪ��ͨ�����ĵ�����
    res=max(res,n-sum);
    // �ܴ�Ȣһ��min
    ans=min(ans,res);
    // ���ظ�������
    return sum;
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}