#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ˼·��ջ���������һ��������˼���⡣������ײ�����ֻ�У�ջ��Ԫ��(��ֵ)�����ƶ�����ǰԪ��(��ֵ)�����ƶ�
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> stk;
        for(int x:nums){
            // ��if+���������ţ�ƣ��������������:
            /*
            1.ջΪ�գ�ֱ����ջ��2.ջ���գ�ջ��Ԫ��Ϊ��ֵ(�������)����x����������л������ҷ��ж�������ײ��3.ջ���գ�ջ��Ԫ��Ϊ��ֵ(���ҷ���)�������xΪ��ֵ(���ҷ���)���Ų�����ײ
            */
            if(stk.empty()||stk.back()<0||x>0)stk.push_back(x);
            /*else���ȱ�ʾ��ջ�ǿգ�ջ��Ԫ��Ϊ��ֵ����xΪ��ֵ���ᷢ����ײ������ֻҪ�ж�ջ����Ԫ���Ƿ���Ҫ��ջ����*/
            else if(stk.back()<=-x){
                while(stk.size()&&stk.size()<-x){
                    stk.pop_back();
                }
                if(stk.size()&&stk.back()==-x)stk.pop_back();
                else if(stk.empty())stk.push_back(x);
            }
        }
        return stk;
    }
};

class Solution1 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;                //����������ģ��ջ

        for (int &item : asteroids)     //����С����
        {
            //ջ��Ϊ�գ�ջ��С�������ҷ��У���ǰС�������������ջ��С���ǽ�С�������ջ��С���Ǳ�ը
            while (!res.empty() && res.back() > 0 && res.back() < -item)
            {
                res.pop_back();
            }
            
            //ջ��Ϊ�գ���ǰС����������У��������Ǵ�С��ͬ�������ͬʱ��ը
            if (!res.empty() && item < 0 && res.back() == -item)
            {
                res.pop_back();
            }

            //1������ǰС�������ҷ��У����ù�ջ��С���ǵķ��з������϶�������ջ��С������ײ��
            //2��ջΪ��ʱ����ǰС������ջ��
            //3����ջ��С����������У����ùܵ�ǰС���ǵķ��з������϶�������ջ��С������ײ��
            else if (item > 0 || res.empty() || res.back() < 0)
            {
                res.push_back(item);
            }
        }
        
        return res;
    }
};
int main()
{
    vector<int> nums={8,-8};
    auto x=Solution().asteroidCollision(nums);
    for(int i:x)cout<<i<<" ";
    cout<<endl;
    return 0;
}