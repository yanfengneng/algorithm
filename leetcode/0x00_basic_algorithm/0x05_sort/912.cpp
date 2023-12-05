#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
int b[N];
class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        int n=a.size();
        memset(b,0,sizeof b);
        merge(a,0,n-1);
        return a;
    }

    void merge(vector<int>& a,int l,int r)
    {
        if(l>=r)return;
        // 1.确定分界点，递归处理左右两段
        int mid=(l+r)>>1;
        merge(a,l,mid),merge(a,mid+1,r);
        // 2.合并左右两段
        //vector<int> b(r-l+1);
        //cout<<b.size()<<endl;
        int i=l,j=mid+1,k=0;
        while(i<=mid||j<=r)
        {
            if(i>mid)b[k++]=a[j++];
            else if(j>r)b[k++]=a[i++];
            else{
                if(a[i]<=a[j])b[k++]=a[i++];
                else b[k++]=a[j++];
            }
        }
        //cout<<k<<endl;
        // 3.还原数组a
        for(i=0;i<k;++i)a[l+i]=b[i];
    }
};

int main()
{
    vector<int> a={5,2,3,1};
    Solution().sortArray(a);
    for(auto x:a)cout<<x<<" ";
    cout<<endl;
    return 0;
}