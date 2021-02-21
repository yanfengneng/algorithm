#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

class Solution {
public:
    int countPairs(vector<int>& a) {
        unordered_map<int,int> hash;
        int res=0,n=a.size();
        for(int i=0;i<n;++i){
            for(int j=1;j<=(1<<21);j<<=1){
                if(hash.count(j-a[i]))res=(res+hash[j-a[i]])%mod;
            }
            hash[a[i]]++;
        }
        return res;
    }
};

int main()
{
    vector<int> a={1048576,1048576};
    cout<<Solution().countPairs(a)<<endl;
    return 0;
}