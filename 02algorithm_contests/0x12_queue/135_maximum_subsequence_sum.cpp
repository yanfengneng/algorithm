#include <bits/stdc++.h>
using namespace std;


const int N = 3e5+10;
int a[N];
int pre[N];// pre[i]=sum(a[0...i-1])��ʹ�õ�������ҿ����䣬pre[i]-pre[j]=sum(a[j...i-1])�����䳤��Ϊ i-j
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
        // ���䳤��Ϊ i-j
        while(q.size() and i-q.front()>m)q.pop_front();
        // ����[j,i-1]���������Ϊ pre[i]-pre[j]
        if(q.size())res=max(res,pre[i]-pre[q.front()]);
        // ���ֶ��е�������
        while(q.size() and pre[q.back()]>=pre[i])q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",res);
    return 0;
}