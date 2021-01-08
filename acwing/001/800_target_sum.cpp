#include <iostream>
using namespace std;

const int N= 1e5+10;
int a[N],b[N];
int n,m,x;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    
    // 指针 i 从前到后扫描数组 a，指针 j 从后向前扫描数组 b
    for(int i=0,j=m-1;i<n;++i)
    {
        // 若a[i]+b[j]>k的话，那么即使i右移之后，他们相加的结果还是会大于x的
        // 因此只用左移指针j，来寻找和等于x，注意数组是升序排序的，好好利用这个性质
        while(j>=0&&a[i]+b[j]>x)j--;
        if(j>=0&&a[i]+b[j]==x)cout<<i<<" "<<j<<endl;
    }
    return 0;
}