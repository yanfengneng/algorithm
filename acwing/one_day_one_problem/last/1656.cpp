#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using LL = long long;
using PLL = pair<LL,LL>;
const int N = 1e5+10;

PLL q[N];
int n,m;

bool check(LL mid)
{
    int cnt=1,pos=q[0].x;
    int i=0;
    while(i<m){
        // �ж�pos+mid�ܷ�������i������
        // �����ܣ����´ε����Ϊpos+mid���i����������Ľϴ�ֵ��������֤�����i������ľ�����ڵ���mid�����ڵ�i��������
        if(pos+mid<=q[i].y){
            pos=max(pos+mid,q[i].x);
            cnt++;
        }
        // ���ܣ���Ѱ����һ����������������
        else{
            while(i<m&&pos+mid>q[i].y)i++;
            if(i>=m)break;
            pos=max(pos+mid,q[i].x);
            cnt++;
        }
    }
    return cnt>=n;
}


// ˼·�����ִ�ת��Ϊ�ж�
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>q[i].x>>q[i].y;
    
    sort(q,q+m);
    
    LL l=0,r=1e18;
    while(l<r)
    {
        LL mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    
    return 0;
}