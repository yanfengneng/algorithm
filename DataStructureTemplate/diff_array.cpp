#include <bits/stdc++.h>
using namespace std;

void insert(int l,int r,int c,vector<int>& b)
{
    b[l]+=c,b[r+1]-=c;
}
int main()
{
    vector<int> a={1,2,3,4,5,6};
    // 差分数组大小开 n+1，这样保证算b[n-1+1]是不会越界，但是在还原差分数组求原数组 a 时，下标只用遍历到 n-1 即可
    // 差分数组 b
    int n=a.size();
    vector<int> b(n+1,0);
    // 构造差分数组，在点(i,i)上插入 a[i]
    for(int i=0;i<n;++i){
        insert(i,i,a[i],b);
    }
    int l,r,c;
    while(cin>>l>>r>>c){
        insert(l,r,c,b);
    }

    // 还原差分数组，求进行区间累加之后的数组 a，其中a[0]=b[0], a[i]=a[0]+a[1]-a[0]+...+a[i]-a[i-1]=b[0]+b[1]+...+b[i]
    // 也就是说 a[i] 是数组 b中下标为所有元素的 b[0...i] 的前缀和。我们只用求到 a[n-1]，不用算 a[n]，因此数组 a 的最大下标为 n-1.
    a[0]=b[0];
    for(int i=1;i<n;++i){
        a[i]=a[i-1]+b[i];
    }
    
    for(int i=0;i<n;++i)cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}