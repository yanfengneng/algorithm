#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int compare(int a,int b){
        return (a>b)?1:(a==b)?0:-1;
    }
    
    //解法1：滑动窗口
    int maxTurbulenceSize_1(vector<int>& A) {
        if(A.empty())return 0;
        if(A.size()==1)return 1;
        
        int left=0,right=1,result=1,N=A.size();
        
        for(;right<N;++right)
        {
            int flag=compare(A[right-1],A[right]);
            if(right==N-1||flag*compare(A[right],A[right+1])!=-1)
            {
                if(flag!=0)result=max(result,right-left+1);
                left=right;
            }
        }
        return result;
    }
    //解法2：动态规划
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()<2)return A.size();
        
        int N=A.size(),dp[N];
        memset(dp,1,sizeof(dp));
        
        dp[0]=1;
        dp[1]=(A[1]!=A[0])?2:1;
        
        int result=max(dp[0],dp[1]);
        
        for(int i=2;i<N;++i)
        {
           if(compare(A[i-2],A[i-1])*compare(A[i-1],A[i])==-1){//瑞流成立
               dp[i]=dp[i-1]+1;
               result=max(result,dp[i]);
           }else if(compare(A[i-1],A[i])!=0){//瑞流不成立且两数不相等，dp[i]=2
               dp[i]=2;
           }
        }
        return result;
    }
};

int main()
{
    vector<int> A{9,4,2,10,7,8,8,1,9};
    cout<<Solution().maxTurbulenceSize(A)<<endl;
    system("pause");
}