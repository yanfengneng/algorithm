#include <iostream>
using namespace std;

const int N = 110;
int q[N];

int n;

void quick_sort(int l,int r)
{
    if(l>=r)return;
    int i=l-1,j=r+1,x=q[l+r>>1];
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    quick_sort(l,j),quick_sort(j+1,r);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>q[i];

    quick_sort(0,n-1);
    //sort(q,q+n);
    //int k=queue(q,q+n)-q;
    // 手动实现unqiue，l为去重之后新序列的尾后元素
    int l=0,r=0;
    while(r<n)
    {
        // 遇到不同的元素直接覆盖在数组前面
        if(r==0||q[r]!=q[r-1])q[l++]=q[r];
        r++;
    }
    cout<<l<<endl;
    for(int i=0;i<l;++i)cout<<q[i]<<" ";
    cout<<endl;
}