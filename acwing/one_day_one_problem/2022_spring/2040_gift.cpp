#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
const int N = 1010;
PII q[N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d%d",&q[i].x,&q[i].y);
    // ����Ʒ�۸��С�������ö��
    sort(q,q+n,[](const auto& a,const auto &b){
       return a.x+a.y<b.x+b.y;
    });
    int res=0;
    // ö�٣�����k����Ʒ����ʹ���Ż�ȯ
    for(int k=0;k<n;++k)
    {
        int total=m-(q[k].x/2+q[k].y);
        // ��k����Ʒ̫���ˣ�����Ҳ����
        if(total<0)continue;
        int cnt=1;
        // ��ʼ����̰��������˵���Ʒ
        for(int i=0;i<n;++i)
            if(i!=k&&total>=q[i].x+q[i].y)
                total-=(q[i].x+q[i].y),cnt++;
        res=max(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}