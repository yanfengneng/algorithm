#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        
        while(!q.empty())
        {
            count++;
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;++i)
            {
                TreeNode* top=q.front();q.pop();
                temp.push_back(top->val);
                if(top->left!=nullptr)q.push(top->left);
                if(top->right!=nullptr)q.push(top->right);
            }
            if(count%2==1)reverse(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
};

int main()
{
    
}