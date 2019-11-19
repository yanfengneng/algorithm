#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> result;
        bool flag[n+1];
        memset(flag,false,sizeof(flag));
        backtrack(result,"",1,n,flag);
        return result[k-1];
    }
    
    void backtrack(vector<string>& result,string track,int index,int n,bool *flag)
    {
        if(index>n)result.push_back(track);
        else{
            for(int i=1;i<=n;++i)
            {
                if(!flag[i])
                {
                    /*choose���̣��������·��*/
                    track.push_back(i+'0');
                    flag[i]=true;
                    /*������һ������*/
                    backtrack(result,track,index+1,n,flag);
                    /*choose���̣��Ƴ�����·��*/
                    track.pop_back();
                    flag[i]=false;
                }
                
            }
        }
    }
};

int main()
{
    string s=Solution().getPermutation(3,3);
}