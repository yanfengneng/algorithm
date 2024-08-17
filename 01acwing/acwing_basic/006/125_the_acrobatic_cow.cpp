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
    
    // ����wi+si�Ӵ�С��������wi+siԽ���ţ����Խ���棬������֤������ֵ��С
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x+a.y>b.x+b.y;
    });
    
    LL res=-1e16;
    for(int i=0;i<n;++i){
        // ��iͷ��ţ�ķ���ֵ������ͷ��������ţ�����ؼ�ȥ��������ǿ׳��
        sum-=q[i].x;
        res=max(res,sum-q[i].y);
    }
    cout<<res<<endl;
    return 0;
}