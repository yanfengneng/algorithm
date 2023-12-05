#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路：栈解决，这是一个很有意思的题。发生碰撞的情况只有：栈顶元素(正值)向右移动，当前元素(负值)向左移动
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> stk;
        for(int x:nums){
            // 这if+或运行真的牛逼，包含所有情况了:
            /*
            1.栈为空，直接入栈；2.栈不空，栈顶元素为负值(向左飞行)，则x无论向左飞行还是向右飞行都不会碰撞；3.栈不空，栈顶元素为正值(向右飞行)，则必须x为正值(向右飞行)，才不会碰撞
            */
            if(stk.empty()||stk.back()<0||x>0)stk.push_back(x);
            /*else首先表示：栈非空，栈顶元素为正值，但x为负值，会发生碰撞；现在只要判断栈顶的元素是否需要出栈即可*/
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
        vector<int> res;                //我们用数组模拟栈

        for (int &item : asteroids)     //遍历小行星
        {
            //栈不为空，栈顶小行星向右飞行，当前小行星向左飞行且栈顶小行星较小的情况，栈顶小行星爆炸
            while (!res.empty() && res.back() > 0 && res.back() < -item)
            {
                res.pop_back();
            }
            
            //栈不为空，当前小行星向左飞行，且俩行星大小相同的情况，同时爆炸
            if (!res.empty() && item < 0 && res.back() == -item)
            {
                res.pop_back();
            }

            //1、若当前小行星向右飞行，不用管栈顶小行星的飞行方向，它肯定不会与栈顶小行星相撞；
            //2、栈为空时，当前小行星入栈；
            //3、若栈顶小行星向左飞行，不用管当前小行星的飞行方向，它肯定不会与栈顶小行星相撞；
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