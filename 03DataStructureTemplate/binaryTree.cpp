#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

/*二叉树的前序遍历,迭代版*/
vector<int> preorderTraversal(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty())
    {
        TreeNode *top=s.top();s.pop();
        result.push_back(top->val);
        /*进栈顺序为根右左，出栈顺序为根左右*/
        if(top->right!=nullptr)s.push(top->right);
        if(top->left!=nullptr)s.push(top->left);
    }
    return result;
}
void helperPreoder(TreeNode* root,vector<int>& result);

/*二叉树的前序遍历，递归版*/
vector<int> preorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperPreoder(root,result);
    return result;
}

/*二叉树的中序遍历：迭代版*/
vector<int> inoderTraversal(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    stack<TreeNode*> s;
    while(!s.empty()||root!=nullptr)
    {
        if(root!=nullptr)//进栈顺序为根左...根左，出栈顺序为左根...左根
        {
            s.push(root);
            root=root->left;
        }
        else//左子树为空时，开始打印根节点，然后再来遍历右子树
        {
            TreeNode* top=s.top();s.pop();
            result.push_back(top->val);
            root=top->right;
        }
        
    }
}

void helperInorder(TreeNode* root,vector<int>& result);

/*二叉树的中序遍历：递归版*/
vector<int> inorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperInorder(root,result);
    return result;
}
 
/*二叉树的后序遍历：迭代版*/
//采用头插法的方式，先遍历右子树，再遍历左子树，将遍历到节点插入数组的最前面得到最后结果
vector<int> postorderTraversal(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    stack<TreeNode*> s;

    while(!s.empty()||root!=nullptr)
    {
        if(root!=nullptr)
        {
            s.push(root);
            result.insert(result.begin(),root->val);
            root=root->right;
        }
        else
        {
            TreeNode *top=s.top();s.pop();
            root=top->left;
        }
    }
    return result;
}

void helperPostorder(TreeNode* root,vector<int>& result);

/*二叉树的后序遍历：递归版*/
vector<int> postorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperPostorder(root,result);
    return result;
}

/*二叉树的层序遍历：广度优先搜索*/
vector<vector<int>> levelOrder(TreeNode* root)
 {
    vector<vector<int>> result; 
    if(nullptr==root)return result;
    queue<TreeNode *> qt;
    qt.push(root);
        
    while(!qt.empty())
    {
        vector<int> temp;
        int qLen=qt.size();//每一层节点个数
        for(int i=0;i<qLen;++i)//当前层的所有节点出队列，节点值存储在临时数组中，下一层的所有节点全部进队列中
        {
            TreeNode* node=qt.front();qt.pop();
            temp.push_back(node->val);
            //单个节点的左右节点进队列
            if(node->left)qt.push(node->left);
            if(node->right)qt.push(node->right);
        }
        result.push_back(temp);//当前层的节点存储在二维数组中
    }
    return result;//返回二维数组
}

/*创造一颗二叉树*/
void createBiTree(TreeNode* root)
{
	int val;
    cin>>val;
    if(val==0)//0表示空节点
        root=nullptr;
    else{
        root=new TreeNode(val);
        createBiTree(root->left);
        createBiTree(root->right);
    }
}

int main()
{
    TreeNode* T;
    createBiTree(T);
    levelOrder(T);
    system("pause");
}

void helperPreoder(TreeNode* root,vector<int>& result)
{
    if(root==nullptr)return;
    result.push_back(root->val);
    helperPreoder(root->left,result);
    helperPreoder(root->right,result);
}

void helperInorder(TreeNode* root,vector<int>& result)
{
    if(root==nullptr)return;
    /*一直递归左子树直至到达叶子节点*/
    helperInorder(root->left,result);
    /*左子树为空时，开始打印根节点*/
    result.push_back(root->val);
    /*开始递归根节点的右子树*/
    helperInorder(root->right,result);
}

void helperPostorder(TreeNode* root,vector<int>& result)
{
    if(root==nullptr)return;
    helperPostorder(root->left,result);
    helperPostorder(root->right,result);
    result.push_back(root->val);
}