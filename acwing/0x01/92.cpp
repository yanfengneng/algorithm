#include <iostream>
using namespace std;

int n;

//state�ڶ������µ�ÿһλ���ִ���һ���¼���1��ʾ�����ֱ�ѡȡ�ˣ������ûѡȡ
void dfs(int u,int state){
    if(u==n){//����ݹ�߽�
        for(int i=0;i<n;++i){
            if(state>>i&1)//state�ĵ�iλ���ֱ�ѡȡ�ˣ�����i�Ǵ�0��ʼ�ģ���Ӧ�±꣬����Ҫ��1
                cout<<i+1<<" ";
        }
        cout<<endl;
        return;
    }
    //����ö�٣�state�ĵ�uλ����ѡȡ��ѡȡ
    dfs(u+1,state);
    dfs(u+1,state|(1<<u));
}

int main()
{
    cin>>n;
    dfs(0,0);
    return 0;
}