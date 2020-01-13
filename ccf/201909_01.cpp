#include <iostream>
#include <cmath>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
int main()
{
    int n,m,T=0,K=0,P=0;
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
           K=i;
           P=abs(b);
        }
    }
    cout<<T<<" "<<K<<" "<<P<<endl;
    system("pause");
}