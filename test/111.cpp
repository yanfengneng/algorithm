#include <iostream>
#include <cstring>
using namespace std;

bool visited[21]={false};

void backtrack(int index,int t,int& count){
    if(index>t)count++;
    for(int i=1;i<=t;++i){
        if(index!=i&&!visited[i]){
            visited[i]=true;
            backtrack(index+1,t,count);
            visited[i]=false;
        }
    }
}

int main()
{
    int n,t;
    cin>>n;
    int count=0;
    int res[n]={0};
    for(int i=0;i<n;++i){
        cin>>t;
        count=0;
        memset(visited,false,sizeof(visited));
        backtrack(1,t,count);
        res[i]=count;
    }
    for(int i=0;i<n;++i){
        cout<<res[i]<<endl;
    }
    system("pause");
}