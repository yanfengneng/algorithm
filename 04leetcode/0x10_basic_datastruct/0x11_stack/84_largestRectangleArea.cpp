#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ��⣺ά��һ������������ջ������ǰ���ε��������ջ���������ʱ����ջ������͵�ջ��˳����㱻�������ε����
    int largestRectangleArea(vector<int>& heights) {
        // ǰ���0��Ϊ�˴���߽����⣬��[2,4]����������0�ͻᵼ��st���ᵯջ��0��2��4���������ò�����ȷ��
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
                // left��ʾ������ܵ��������߽磬right��ʾ������ܵ�������ұ߽�
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