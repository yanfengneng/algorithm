#include <iostream>
using namespace std;

int n,m;

// u表示枚举的次数，count表示选取了几个数字，二进制数state表示选取某位数字的状态
void dfs(int u,int count,int state)
{
    // 选不到m个数字了，表示失败方案
    if(n+count-u<m)return;

    // 选到m个数字了，直接输出
    if(count==m){
        for(int i=0;i<n;++i){
            if(state>>i&1)// i位数字被选取了，输出数字i+1，下标是从0开始的，因此要加1
                cout<<i+1<<" ";
        }
        cout<<endl;
        return;
    }

    // 没选到m个数字，表示失败方案
    if(u==n)return;
    // 进行dfs枚举，由于要求按字典序，因此选取第u位数字应排在前面
    dfs(u+1,count+1,state|(1<<u));
    dfs(u+1,count,state);
}

int main()
{
    cin>>n>>m;
    dfs(0,0,0);
    return 0;
}