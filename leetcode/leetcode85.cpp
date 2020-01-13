#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    //利用84题最大矩阵的解法：单调栈
    int largestRectangleArea(vector<int> heights){
        if(heights.empty())return 0;
        //1、首尾数组首尾加0
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        int res=0;
        stack<int> st;
        for(int i=0;i<heights.size();++i){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int cur=st.top();st.pop();
//i-top-1表示矩形的宽，其中top表示height[cur]之前有top个元素需要减去，-1表示i所指向的元素也需要减去，heights[cur]表示矩形的高
                res=max(res,(i-st.top()-1)*heights[cur]);
            }
            st.push(i);
        }
        return res;
    }
public:
    //题解：本题与上一题一样的，不过需要对每一行求出元素对应的高度
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return 0;
        int m=matrix.size(),n=matrix[0].size(),area=0;
        vector<int> heights(n,0);//共有n列，计算每行元素对应的高度
        for(auto row:matrix){
            for(int i=0;i<n;++i){
                //若该行的i列元素为1，那么它的高度为上一行对应高度+1；若该行的i列元素不为1，那么它的高度为0
                //对于第一行可以看作在第0行的基础上，进行高度的累加
                heights[i]=row[i]=='1'?heights[i]+1:0;
            }
            area=max(area,largestRectangleArea(heights));
        }
        return area;
    }
};

int main()
{
    vector<vector<char>> matrix{{'1','0'},{'1','0'}};
    int area=Solution().maximalRectangle(matrix);
    cout<<area<<endl;
    system("pause");
}