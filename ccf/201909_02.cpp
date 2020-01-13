#include <bits/stdc++.h>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

int main()
{
    int n,T=0,D=0,E=0;
    cin>>n;
    bool flag[n]={false};//用来表示第i颗树是否落果
    for(int i=0;i<n;++i){
        int m,a,b;
        cin>>m>>a;
        for(int j=1;j<m;++j){
            cin>>b;
            if(b<=0)a+=b;//进行疏果操作
            else if(a>b){//有落果现象
                a=b;
                flag[i]=true;
            }
        }
        T+=a;//统计苹果总数
    }
    D=count(flag,flag+n,true);
    for(int i=0;i<n;++i){//统计连续三棵树是否现在落果现象，注意此时的树是一个圈
        if(flag[i]&&flag[(i+1)%n]&&flag[(i+2)%n])
            E++;
    }
    cout<<T<<" "<<D<<" "<<E<<" "<<endl;
    return 0;
}