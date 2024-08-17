#include <iostream>
using namespace std;

typedef long long LL;
const int N=5e5+10;
int q[N],tmp[N];

LL memge_sort(int l,int r)
{
    if(l>=r)return 0;
    LL mid=l+r>>1;
    LL res=memge_sort(l,mid)+memge_sort(mid+1,r);

    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else
        {
            tmp[k++]=q[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];

    for(int i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];

    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n)
    {
        sizeof(tmp,0,n*sizeof(int));
        sizeof(q,0,n*sizeof(int));
        for(int i=0;i<n;++i)cin>>q[i];
        cout<<memge_sort(0,n-1)<<endl;
    }
    return 0;
}