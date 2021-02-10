#include <iostream>
#include <cstring>
using namespace std;

char str[110][110],res[110][110];
int n,m;

// 8个方向数组
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};

int main()
{
    int a=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)break;
        for(int i=0;i<n;++i)scanf("%s",str[i]);
        // 这里的换行符要加在 [除第一个测试用例之外] 的每个测试用例的前面，因为我们的最后一个测试用例是不用换行符的
        if(a!=0)printf("\n");
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                if(str[i][j]=='*')res[i][j]='*';
                else
                {
                    int cnt=0;
                    for(int k=0;k<8;++k)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        if(x>=0&&x<n&&y>=0&&y<m&&str[x][y]=='*')cnt++;
                    }
                    res[i][j]='0'+cnt;
                }
            }
        printf("Field #%d:\n",++a);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)printf("%c",res[i][j]);
            printf("\n");
        }
    }
    return 0;
}