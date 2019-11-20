#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(result,"",0,4,s,s.size());
        return result;
    }
    void backtrack(vector<string>& result,string track,size_t i,int flag,string s,size_t n)
    {
        if(i==n&&flag==0)
        {
            track.pop_back();
            result.push_back(track);
            return;
        }   
        if(flag<0)return;
        else
        {
            for(size_t j=i;j<i+3;++j)
            {
                if(j<n)
                {
                    if(i==j&&s[j]=='0')
                    {
                        backtrack(result,track+s[j]+'.',j+1,flag-1,s,n);
                        break;
                    }
                    if(stoi(s.substr(i,j+1-i))<=255)
                    {
                        backtrack(result,track+s.substr(i,j+1-i)+'.',j+1,flag-1,s,n);
                    }
                }
            }
        }
    }
};

int main()
{
    string str="25525511135";
    vector<string> result=Solution().restoreIpAddresses(str);
    for(auto it:result)
        cout<<it<<endl;
    return 0;
}