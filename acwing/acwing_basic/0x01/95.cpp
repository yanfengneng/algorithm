#include <iostream>
#include <cstring>
using namespace std;
#define INT 100000000

char g[10][10];
// 方向数组，5个方向，中、上、右、下、左
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};

// 转变开关
void turn(int x,int y)
{
    for(int i=0;i<5;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        // g[a][b]的值进行改变，从1改为0，0改为1
        if(a>=0&&a<5&&b>=0&&b<5)
        {
            // g[a][b]='0'+('1'-g[a][b]);
            g[a][b]^=1;// 与上面语句一样的，0变成1，1变成0
        }
    }
}

int work()
{
    int ans=INT;
    // 第一行有32种枚举方法，枚举0-31可以使用一个5位二进制数就行了
    for(int k=0;k<1<<5;++k)
    {
        // res用来记录开灯的次数
        int res=0;
        char backup[10][10];// 由于要枚举每种状态，所以要备份数组
        memcpy(backup,g,sizeof g);
        // 完成第一行的枚举后，就固定第一行
        for(int j=0;j<5;++j)
            if(k>>j&1)// 第j位被选取了，需要turn一下
            {
                res++;
                turn(0,j);// 0行j列
            }
        
        // 第一行已经固定了，若在第一行中发现了0，就把它的下一个位置按一下，剩下的行以此类推
        // 最后一行不用按，因为没有下一行给他按了，所以i最大取到3
        for(int i=0;i<4;++i)
            for(int j=0;j<5;++j)
                if(g[i][j]=='0')
                {
                    res++;
                    turn(i+1,j);
                }

        // 最后一行不全为0的话，说明点击方式不合法
        bool flag=true;
        for(int j=0;j<5;++j){
            if(g[4][j]=='0')
            {
                flag=false;
                break;
            }
        }

        // 方案数合法的话，更新下最小方案数
        if(flag)ans=min(ans,res);

        // 恢复数组，进行下一次枚举
        memcpy(g,backup,sizeof g);
    }

    // 6步以内无法使所有灯变亮，则输出"-1"
    if(ans>6)ans=-1;
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<5;++i)cin>>g[i];
        cout<<work()<<endl;
    }
    return 0;
}