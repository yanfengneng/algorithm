#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> recond={"Fizz","Buzz","FizzBuzz"};
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;++i){
            if((i%3==0)&&(i%5==0))res.push_back(recond[2]);
            else if(!(i%3))res.push_back(recond[0]);
            else if(!(i%5))res.push_back(recond[1]);
            else res.push_back(to_string(i));
        }
        return res;
    }
};

int main()
{
    vector<string> res=Solution().fizzBuzz(3);
    for(auto r:res)cout<<r<<" ";
    cout<<endl;
}