#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    //����84��������Ľⷨ������ջ
    int largestRectangleArea(vector<int> heights){
        if(heights.empty())return 0;
        //1����β������β��0
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        int res=0;
        stack<int> st;
        for(int i=0;i<heights.size();++i){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int cur=st.top();st.pop();
//i-top-1��ʾ���εĿ�����top��ʾheight[cur]֮ǰ��top��Ԫ����Ҫ��ȥ��-1��ʾi��ָ���Ԫ��Ҳ��Ҫ��ȥ��heights[cur]��ʾ���εĸ�
                res=max(res,(i-st.top()-1)*heights[cur]);
            }
            st.push(i);
        }
        return res;
    }
public:
    //��⣺��������һ��һ���ģ�������Ҫ��ÿһ�����Ԫ�ض�Ӧ�ĸ߶�
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return 0;
        int m=matrix.size(),n=matrix[0].size(),area=0;
        vector<int> heights(n,0);//����n�У�����ÿ��Ԫ�ض�Ӧ�ĸ߶�
        for(auto row:matrix){
            for(int i=0;i<n;++i){
                //�����е�i��Ԫ��Ϊ1����ô���ĸ߶�Ϊ��һ�ж�Ӧ�߶�+1�������е�i��Ԫ�ز�Ϊ1����ô���ĸ߶�Ϊ0
                //���ڵ�һ�п��Կ����ڵ�0�еĻ����ϣ����и߶ȵ��ۼ�
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