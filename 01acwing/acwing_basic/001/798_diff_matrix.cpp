#include <iostream>

using namespace std;

const int N=1010;
int a[N][N],b[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);

    // �������ĳ�ʼ��
    // ����������ĳ�ʼ��ȷʵ������⣬����ͨ�����ԵĻ����� b ȷʵ����ʼ�����������
    // ��Ϊ��ÿ��С�����ڲ��� a[i][j] ʱ������Χ��4��ֵҲ��仯����������a������Ԫ�ز���󣬾ͻ��γɲ�����ݣ������е�֤����ϵ�Ͳ��ù��ˣ���ס���ģ�����
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            insert(i,j,i,j,a[i][j]);
    
   
    while(q--)
    {
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        // �����������μ��� c
        insert(x1,y1,x2,y2,c);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            // ��ԭ���� a����ǰ׺��
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}