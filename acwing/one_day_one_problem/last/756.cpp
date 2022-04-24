#include <iostream>
using namespace std;

int a[110][110];
int n,m;

void slove(int n,int m)
{
    // 确定四条边的位置
    int up=0,down=n-1,left=0,right=m-1;
    int val=1;
    while(true)
    {
        // 固定up，从左滑到右
        for(int i=left;i<=right;++i)a[up][i]=val++;
        if(++up>down)break;// up下移一个单位

        // 固定right，从上滑到下
        for(int i=up;i<=down;++i)a[i][right]=val++;
        if(--right<left)break;// right右移一个单位

        // 固定down，从左滑到右
        for(int i=right;i>=left;--i)a[down][i]=val++;
        if(--down<up)break;// down上移一个单位

        // 固定left，从下滑到上
        for(int i=down;i>=up;--i)a[i][left]=val++;
        if(++left>right)break;// left左移一个单位
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