#include <iostream>
using namespace std;

int n;

//state在二进制下的每一位数字代表一个事件，1表示该数字被选取了，否则就没选取
void dfs(int u,int state){
    if(u==n){//到达递归边界
        for(int i=0;i<n;++i){
            if(state>>i&1)//state的第i位数字被选取了，由于i是从0开始的，对应下标，所以要加1
                cout<<i+1<<" ";
        }
        cout<<endl;
        return;
    }
    //进行枚举，state的第u位不被选取或被选取
    dfs(u+1,state);
    dfs(u+1,state|(1<<u));
}

int main()
{
    cin>>n;
    dfs(0,0);
    return 0;
}