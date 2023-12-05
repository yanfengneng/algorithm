#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LL = long long;
class Solution {
public:
    // 思路类比三数之和
    int numTriplets(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        return solve(a,b)+solve(b,a);
    }

    int solve(vector<int> a,vector<int> b){
        int n=a.size(),m=b.size();
        int res=0;
        for(int i=0;i<n;++i){
            LL square=1LL*a[i]*a[i];
            int l=0,r=m-1;
            while(l<r){
                if(square<1LL*b[l]*b[r])r--;
                else if(square>1LL*b[l]*b[r])l++;
                else{
                    if(b[l]==b[r]){
                        int c=0;
                        while(l<=r&&b[l]==b[r]){
                            l++,c++;
                        }
                        cout<<c<<endl;
                        res+=c*(c-1)/2;
                    }
                    else{
                        int c0=1,c1=1;
                        // 缩小区间
                        l++,r--;
                        // 分别对重复元素进行计数
                        while(l<=r&&b[l]==b[l-1])l++,c0++;
                        while(l<=r&&b[r]==b[r+1])r--,c1++;
                        cout<<"--"<<c0<<" "<<c1<<endl;
                        res+=c0*c1;
                    }
                }
            }
        }
        cout<<"--"<<res<<endl;
        return res;
    }
};

int main()
{
    vector<int> a={4,1,4,1,12},b={3,2,5,4};
    Solution().numTriplets(a,b);
    return 0;
}