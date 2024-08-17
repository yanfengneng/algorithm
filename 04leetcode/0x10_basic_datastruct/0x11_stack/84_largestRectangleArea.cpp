#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 题解：维护一个单调递增的栈，若当前矩形的面积大于栈顶矩形面积时，入栈；否则就弹栈，顺便计算被弹出矩形的面积
    int largestRectangleArea(vector<int>& heights) {
        // 前后加0是为了处理边界问题，如[2,4]不在最后面加0就会导致st不会弹栈（0，2，4），这样得不到正确答案
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int res=0;
        stack<int> st;
        for(int i=0;i<heights.size();++i)
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                int cur=st.top();
                st.pop();
                // left表示面积所能到达的最左边界，right表示面积所能到达的最右边界
                int left=st.top()+1,right=i-1;
                res=max(res,(right-left+1)*heights[cur]);
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
    vector<int> h={2,1,5,6,2,3};
    cout<<Solution().largestRectangleArea(h)<<endl;
}