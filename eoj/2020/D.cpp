#include <bits/stdc++.h>
using namespace std;

using LL =long long;

struct node
{
    // �뾶���ߡ������
    LL r,h,s;
}a[1010];

int n,m;

bool cmp(node x,node y)
{
    return x.s>y.s;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i].r>>a[i].h;
        a[i].s=2*a[i].r*a[i].h;
    }

    // ö�������ӻ���������ȸ�������Ÿ��򣬱���̰�ĵ�ѡ��m-1�����Ĳ����
    sort(a,a+n,cmp);
    LL res=0;
    // �̶�ѡ�� Բ��i �ĵ����+�������Ȼ��̰�ĵ�ѡ��ǰm-1�����Ĳ����
    for(int i=0;i<n;++i)
    {
        LL sum=a[i].s+a[i].r*a[i].r;
        int cnt=1;
        for(int j=0;j<n&&cnt<m;++j)
        {
            // Բ�������ظ���ͬʱ֮���Բ���ĵ��������Ҫ�ȵ�i��Բ���ĵ����ҪС
            if(i==j||a[j].r>a[i].r)continue;
            sum+=a[j].s;
            cnt++;
        }
        if(cnt==m)res=max(res,sum);
    }
    cout<<res<<endl;
    return 0;
}