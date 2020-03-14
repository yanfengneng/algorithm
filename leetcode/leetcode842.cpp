#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(const string& S) {
        vector<int> res;
        int i=0;
        for(int j=i+1;j<S.size();++j){
            for(int k=j+1;k<S.size();++k){
                res.clear();
                if(backtrack(S,i,j,k,res)){
                    if(res.size()>2){
                        return res;
                    }
                }
            }
        }
        return {};
    }

    bool backtrack(const string& S,int i,int j,int k,vector<int>& res){
        if((S[i]=='0'&&j-i>1)||(S[j]=='0'&&k-j>1))return false;//s[i]、s[j]为'0'，相差一位的话，满足题意
        long long a=0,b=0;
        for(int c=i;c<j;++c){
            a=a*10+S[c]-'0';
            if(a>INT_MAX)return false;
        }
        for(int c=j;c<k;++c){
            b=b*10+S[c]-'0';
            if(b>INT_MAX)return false;
        }
        if(k==S.size()){
            res.push_back(a);
            res.push_back(b);
            return true;
        }
        string sum=to_string(a+b);
        for(int c=0;c<sum.size();++c){
            if(S[c+k]!=sum[c])return false;
        }
        res.push_back(a);
        return backtrack(S,j,k,k+sum.size(),res);
    }
};

int main()
{
    vector<int> res=Solution().splitIntoFibonacci("123456579");
    for(auto it:res)cout<<it<<" ";
    cout<<endl;
}