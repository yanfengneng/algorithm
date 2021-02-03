#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,w;
// cab[i] ������ŵ�i��С��װ��èè����
int c[25],cab[25];
int res=0;

// idx ��ʾ ����� idx ֻèè��������С����cnt ��ʾ�����Ѿ����� cnt ��С����
void dfs(int idx,int cnt)
{
    // ��֦������ǰ���С��������Ŀǰ����Сֵ�ˣ����Ǽ���������ȥҲ�����ҵ����Ž�������м�֦
    if(cnt>=res)return;
    // �ҵ�һ�����н�
    if(idx==n)
    {
        res=min(res,cnt);
        return;
    }
    /*ö��ѡ���б���[1,cnt]������ѡһ������װèè*/
    for(int i=1;i<=cnt;++i)
    {
        // ��i��С���ϻ���װ��idxֻèè����װȡèè
        if(cab[i]+c[idx]<=w)
        {
            /*choose���̣��������*/
            cab[i]+=c[idx];
            /*������һ�ξ���*/
            dfs(idx+1,cnt);
            /*unchooose���̣��Ƴ��þ���*/
            cab[i]-=c[idx];
        }
    }

    /*������һ���µ�С����װèè*/
    /*����˴ξ���*/
    cab[cnt+1]=c[idx];
    /*������һ�ξ���*/
    dfs(idx+1,cnt+1);
    /*�Ƴ��˴ξ���*/
    cab[cnt+1]=0;
}

int main()
{
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;++i)scanf("%d",&c[i]);
    // �ɴ�С����̰���������������صģ���������������֧��������
    sort(c,c+n);        // ����С��������
    reverse(c,c+n);     // �ٷ�תһ�£�����ɴ�С����

    // ������ÿ��èèһ��С��
    res=n;
    dfs(0,1);
    printf("%d",res);
    return 0;
}