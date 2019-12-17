#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m,T=0,K=0,P=0;
    cout<<"请输入："<<endl;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        //i颗的苹果个数，疏果总数，疏果树
        int a,b=0,c;
        cin>>a;
        T+=a;
        for(int j=0;j<m;++j){
            cin>>c;
            b+=c;
        }
        T+=b;
        if(abs(b)>P){
            P=i;
            K=abs(b);
        }
    }
    cout<<T<<" "<<K<<" "<<P<<endl;
}