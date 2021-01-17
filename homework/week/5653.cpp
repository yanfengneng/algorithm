#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen=0,res=0;
        for(auto& it:rectangles)
        {
            int a=it[0],b=it[1];
            if(maxlen<max({a,b}))
            {
                maxlen=max(a,b);
                res=0;
            }
            else if(maxlen=max({a,b}))
            {
                res++;
            }
        }
        return res;
    }
};