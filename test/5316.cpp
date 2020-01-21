#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream str(s);
        string word;
        int length=0;
        while(str>>word){
            length=max(length,int(word.size()));
        }
        vector<string> res(length);
        istringstream str1(s);
        while(str1>>word){
            int size=word.size();
            for(int i=0;i<length;++i){
                if(i<size){
                    res[i].push_back(word[i]);
                }
                else{
                    res[i].push_back(' ');
                }
            }
        }
        for(int i=0;i<length;++i){
            int j=res[i].size()-1;
            while(res[i][j]==' '&&j>=0){
                res[i].pop_back();
                j--;
            }
        }
        return res;
    }
};

int main()
{
    vector<string> res=Solution().printVertically("TO BE OR NOT TO BE");
    for(auto it:res){
        cout<<it<<endl;
    }
}