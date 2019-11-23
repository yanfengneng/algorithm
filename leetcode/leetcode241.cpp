#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

class Solution {
private:
    map<pair<int,int>,vector<int>> m;
public:
    vector<int> diffWaysToCompute(string input){
        return ways(input,0,input.size());
    }

    vector<int> ways(const string& input,int left,int right)
    {
        //判断区间是否添加到m中
        if(m.find(make_pair(left,right))!=m.end())
            return m[make_pair(left,right)];
        vector<int> res;
        for(int i=left;i<right;++i)
        {
            if(input[i]=='-'||input[i]=='+'||input[i]=='*')
            {
                vector<int> l=ways(input,left,i);
                vector<int> r=ways(input,i+1,right);
                for(auto vl:l)for(auto vr:r)
                {   
                    cout<<vl<<" "<<vr<<" "<<ops(input[i],vl,vr)<<endl;
                    res.push_back(ops(input[i],vl,vr));
                }
            }
        }
        if(res.size()==0)res.push_back(stoi(input.substr(left,right-left)));
        m[make_pair(left,right)]=res;
        return res;
    }

    int ops(char op, int l, int r) {
        switch(op) {
            case '+':
                return l+r;
            case '-':
                return l-r;
            case '*':
                return l*r;
        }
        return 0;
    }
};

int main()
{
    string input="2*3-4*5";
    vector<int> res=Solution().diffWaysToCompute(input);
    system("pause");
}