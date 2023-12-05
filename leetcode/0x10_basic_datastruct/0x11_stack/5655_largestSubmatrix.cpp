#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 维护一个单调递增的栈，也就是 t84 的最大矩形面积
    int largestRectangleArea(vector<int> heights){
        sort(heights.begin(),heights.end());
       heights.insert(heights.begin(),0);
       heights.push_back(0);
       int res=0;
       stack<int> st;
       for(int i=0;i<heights.size();++i)
       {
           // 不满足递增栈了，开始进行弹栈，顺便计算面积
           while(!st.empty()&&heights[st.top()]>heights[i])
           {
               int cur=st.top();
               st.pop();
               // heights[i]用不到，因为太矮了，所以右边界只能到i-1；左边界为它自己本身，也就是top+1
               int left=st.top()+1,right=i-1;
               res=max(res,(right-left+1)*heights[cur]);
           }
           st.push(i);
       }
       return res;
    }
public:
    // 题解：本题就是t85的弱鸡版本，奈何本人太菜了周赛时没做出来
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        // 将每一列转换为高度
        vector<int> heights(m,0);
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                // 统计每列的高度
                heights[j]=matrix[i][j]==1?heights[j]+1:0;
            }
            res=max(res,largestRectangleArea(heights));
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix={{0,0,1},{1,1,1},{1,0,1}};
    cout<<Solution().largestSubmatrix(matrix)<<endl;
}