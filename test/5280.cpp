#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        map<int,vector<int>> record;
        int n=group.size();
        for(int i=0;i<n;++i){
            record[group[i]].push_back(i);
        }
        vector<vector<int>> result;
        for(auto it:record){
            if(it.first<it.second.size()){
                auto begin=it.second.begin(),end=it.second.end();
                while(begin!=end){
                    result.push_back(vector<int>(begin,begin+it.first));
                    begin+=it.first;
                }
            }
            else{
                result.push_back(it.second);
            }
        }
        return result;
    }
};