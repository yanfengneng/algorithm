#include <iostream>
using namespace std;

int n,m;

// u��ʾö�ٵĴ�����count��ʾѡȡ�˼������֣���������state��ʾѡȡĳλ���ֵ�״̬
void dfs(int u,int count,int state)
{
    // ѡ����m�������ˣ���ʾʧ�ܷ���
    if(n+count-u<m)return;

    // ѡ��m�������ˣ�ֱ�����
    if(count==m){
        for(int i=0;i<n;++i){
            if(state>>i&1)// iλ���ֱ�ѡȡ�ˣ��������i+1���±��Ǵ�0��ʼ�ģ����Ҫ��1
                cout<<i+1<<" ";
        }
        cout<<endl;
        return;
    }

    // ûѡ��m�����֣���ʾʧ�ܷ���
    if(u==n)return;
    // ����dfsö�٣�����Ҫ���ֵ������ѡȡ��uλ����Ӧ����ǰ��
    dfs(u+1,count+1,state|(1<<u));
    dfs(u+1,count,state);
}

int main()
{
    cin>>n>>m;
    dfs(0,0,0);
    return 0;
}