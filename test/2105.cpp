#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& a, int A, int B) {
        int n=a.size();
        int tA=A,tB=B,cntA=0,cntB=0;
        for(int i=0;i<=n/2;++i){
            if(i==n/2){
                if(n&1){
                    int mx=max(tA,tB);
                    cout<<tA<<" "<<tB<<endl;
                    if(mx-a[i]>=0)return cntA+cntB;
                    else return cntA+cntB+1;
                }
                else{
                    return cntA+cntB;
                }
            }
            else{
                if(tA-a[i]>=0)tA-=a[i];
                else cntA++,tA=A-a[i];
                
                if(tB-a[n-1-i]>=0)tB-=a[n-1-i];
                else cntB++,tB=B-a[n-1-i];
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> a{1,2,4,4,5};
    Solution().minimumRefill(a,6,5);
    return 0;
}