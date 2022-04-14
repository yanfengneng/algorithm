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

    // ��ѡ���б���ѡ�����
    for(int i=0;i<n;++i)
    {
        if(!flag[i])
        {
            /*choose����*/
            path[index]=i+1;
            flag[i]=true;
            
            /*������һ������*/
            dfs(index+1);

            /*unchoose���̣�path�ǲ���Ҫ�ָ��ģ���Ϊ�Ḳ��*/
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