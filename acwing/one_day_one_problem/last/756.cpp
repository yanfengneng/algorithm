#include <iostream>
using namespace std;

int a[110][110];
int n,m;

void slove(int n,int m)
{
    // ȷ�������ߵ�λ��
    int up=0,down=n-1,left=0,right=m-1;
    int val=1;
    while(true)
    {
        // �̶�up�����󻬵���
        for(int i=left;i<=right;++i)a[up][i]=val++;
        if(++up>down)break;// up����һ����λ

        // �̶�right�����ϻ�����
        for(int i=up;i<=down;++i)a[i][right]=val++;
        if(--right<left)break;// right����һ����λ

        // �̶�down�����󻬵���
        for(int i=right;i>=left;--i)a[down][i]=val++;
        if(--down<up)break;// down����һ����λ

        // �̶�left�����»�����
        for(int i=down;i>=up;--i)a[i][left]=val++;
        if(++left>right)break;// left����һ����λ
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    slove(n,m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}