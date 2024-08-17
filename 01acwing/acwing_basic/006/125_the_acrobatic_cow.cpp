#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using LL = long long;
using PLL = pair<LL,LL>;
#define x first
#define y second
PLL q[N];

int n;

int main()
{
    scanf("%d",&n);
    LL sum=0;
    for(int i=0;i<n;++i){
        scanf("%ld%ld",&q[i].x,&q[i].y);
        sum+=q[i].x;
    }
    
    // 按照wi+si从大到小进行排序，wi+si越大的牛放在越下面，这样保证最大风险值最小
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x+a.y>b.x+b.y;
    });
    
    LL res=-1e16;
    for(int i=0;i<n;++i){
        // 第i头奶牛的风险值等于它头上所有奶牛的体重减去它的身体强壮度
        sum-=q[i].x;
        res=max(res,sum-q[i].y);
    }
    cout<<res<<endl;
    return 0;
}