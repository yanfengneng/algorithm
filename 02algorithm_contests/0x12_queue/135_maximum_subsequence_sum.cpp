#include <bits/stdc++.h>
using namespace std;


const int N = 3e5+10;
int a[N];
int pre[N];// pre[i]=sum(a[0...i-1])。使用的是左闭右开区间，pre[i]-pre[j]=sum(a[j...i-1])，区间长度为 i-j
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i-1]);
        pre[i]=pre[i-1]+a[i-1];
    }
    int res=INT_MIN;
    deque<int> q;
    for(int i=0;i<=n;++i)
    {
        // 区间长度为 i-j
        while(q.size() and i-q.front()>m)q.pop_front();
        // 区间[j,i-1]的子区间和为 pre[i]-pre[j]
        if(q.size())res=max(res,pre[i]-pre[q.front()]);
        // 保持队列单调递增
        while(q.size() and pre[q.back()]>=pre[i])q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",res);
    return 0;
}