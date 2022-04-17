#include <iostream>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            int n=s.size();
            string tmp;
            for(int i=0;i<n;i+=k){
                int x=0;
                for(int j=0;j<k;++j){
                    if(j+i<n)x+=(s[j+i]-'0');
                }
                tmp+=to_string(x);
            }
            s=tmp;
        }
        return s;
    }
};

int main()
{
    cout<<Solution().digitSum("11111222223",3)<<endl;
    return 0;
}