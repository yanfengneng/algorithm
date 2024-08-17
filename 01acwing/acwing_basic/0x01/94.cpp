#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> path;

void dfs(int u,int state){
    if(u==n){// ����ݹ�߽�
        for(int p:path)cout<<p<<" ";
        cout<<endl;
        return;
    }
    for(int i=0;i<n;++i){
        if(!(state>>i&1)){// ����iû�б�ѡ�������ѡ��
            path.push_back(i+1);
            dfs(u+1,state|(1<<i));// ѡȡ����i
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