#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // ά��һ������������ջ��Ҳ���� t84 �����������
    int largestRectangleArea(vector<int> heights){
        sort(heights.begin(),heights.end());
       heights.insert(heights.begin(),0);
       heights.push_back(0);
       int res=0;
       stack<int> st;
       for(int i=0;i<heights.size();++i)
       {
           // ���������ջ�ˣ���ʼ���е�ջ��˳��������
           while(!st.empty()&&heights[st.top()]>heights[i])
           {
               int cur=st.top();
               st.pop();
               // heights[i]�ò�������Ϊ̫���ˣ������ұ߽�ֻ�ܵ�i-1����߽�Ϊ���Լ�����Ҳ����top+1
               int left=st.top()+1,right=i-1;
               res=max(res,(right-left+1)*heights[cur]);
           }
           st.push(i);
       }
       return res;
    }
public:
    // ��⣺�������t85�������汾���κα���̫��������ʱû������
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        // ��ÿһ��ת��Ϊ�߶�
        vector<int> heights(m,0);
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                // ͳ��ÿ�еĸ߶�
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