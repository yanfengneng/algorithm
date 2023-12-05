#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> path;

void dfs(int u,int state){
    if(u==n){// 到达递归边界
        for(int p:path)cout<<p<<" ";
        cout<<endl;
        return;
    }
    for(int i=0;i<n;++i){
        if(!(state>>i&1)){// 数字i没有被选择，则进行选择
            path.push_back(i+1);
            dfs(u+1,state|(1<<i));// 选取数字i
            path.pop_back();
        }
    }
}


int main()
{
    cin>>n;
    dfs(0,0);
    return 0;
}