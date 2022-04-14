#include <iostream>
using namespace std;

const int N = 10;
int n,path[N]={0};
bool flag[N]={0};

void dfs(int index)
{
    if(index==n)
    {
        for(int i=0;i<n;++i)printf("%d ",path[i]);
        puts("");
        return;
    }

    // 从选择列表中选择决策
    for(int i=0;i<n;++i)
    {
        if(!flag[i])
        {
            /*choose过程*/
            path[index]=i+1;
            flag[i]=true;
            
            /*进入下一步决策*/
            dfs(index+1);

            /*unchoose过程，path是不需要恢复的，因为会覆盖*/
            flag[i]=false;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}