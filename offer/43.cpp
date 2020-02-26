#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count=0;
        for(int i=1;i<=n;++i){
            string str=to_string(i);
            for(char ch:str)if(ch=='1')count++;
        }
        return count;
    }
};

int main()
{
    cout<<Solution().countDigitOne(824883294)<<endl;
}