#include <bits/stdc++.h>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

int main()
{
    int n,T=0,D=0,E=0;
    cin>>n;
    bool flag[n]={false};//������ʾ��i�����Ƿ����
    for(int i=0;i<n;++i){
        int m,a,b;
        cin>>m>>a;
        for(int j=1;j<m;++j){
            cin>>b;
            if(b<=0)a+=b;//�����������
            else if(a>b){//���������
                a=b;
                flag[i]=true;
            }
        }
        T+=a;//ͳ��ƻ������
    }
    D=count(flag,flag+n,true);
    for(int i=0;i<n;++i){//ͳ�������������Ƿ������������ע���ʱ������һ��Ȧ
        if(flag[i]&&flag[(i+1)%n]&&flag[(i+2)%n])
            E++;
    }
    cout<<T<<" "<<D<<" "<<E<<" "<<endl;
    return 0;
}