#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 50;
LL c[N][N];

class Solution {
public:
    void combin()
    {
        memset(c,0,sizeof c);
        for(int i=0;i<N;++i){
            for(int j=0;j<=i;++j){
                if(!j)c[i][j]=1;
                else c[i][j]=(c[i-1][j-1]+c[i-1][j]);
            }
        }
    }

    int numTrees(int n) {
        combin();
        return c[2*n][n]/(n+1);
    }
};

int main()
{
    cout<<Solution().numTrees(3)<<endl;
    return 0;
}