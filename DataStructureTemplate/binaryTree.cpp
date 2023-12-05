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

/*��������ǰ�����,������*/
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
        /*��ջ˳��Ϊ�����󣬳�ջ˳��Ϊ������*/
        if(top->right!=nullptr)s.push(top->right);
        if(top->left!=nullptr)s.push(top->left);
    }
    return result;
}
void helperPreoder(TreeNode* root,vector<int>& result);

/*��������ǰ��������ݹ��*/
vector<int> preorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperPreoder(root,result);
    return result;
}

/*�����������������������*/
vector<int> inoderTraversal(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    stack<TreeNode*> s;
    while(!s.empty()||root!=nullptr)
    {
        if(root!=nullptr)//��ջ˳��Ϊ����...���󣬳�ջ˳��Ϊ���...���
        {
            s.push(root);
            root=root->left;
        }
        else//������Ϊ��ʱ����ʼ��ӡ���ڵ㣬Ȼ����������������
        {
            TreeNode* top=s.top();s.pop();
            result.push_back(top->val);
            root=top->right;
        }
        
    }
}

void helperInorder(TreeNode* root,vector<int>& result);

/*������������������ݹ��*/
vector<int> inorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperInorder(root,result);
    return result;
}
 
/*�������ĺ��������������*/
//����ͷ�巨�ķ�ʽ���ȱ������������ٱ��������������������ڵ�����������ǰ��õ������
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

/*�������ĺ���������ݹ��*/
vector<int> postorderTraversal_2(TreeNode* root)
{
    if(root==nullptr)return {};
    vector<int> result;
    helperPostorder(root,result);
    return result;
}

/*�������Ĳ�������������������*/
vector<vector<int>> levelOrder(TreeNode* root)
 {
    vector<vector<int>> result; 
    if(nullptr==root)return result;
    queue<TreeNode *> qt;
    qt.push(root);
        
    while(!qt.empty())
    {
        vector<int> temp;
        int qLen=qt.size();//ÿһ��ڵ����
        for(int i=0;i<qLen;++i)//��ǰ������нڵ�����У��ڵ�ֵ�洢����ʱ�����У���һ������нڵ�ȫ����������
        {
            TreeNode* node=qt.front();qt.pop();
            temp.push_back(node->val);
            //�����ڵ�����ҽڵ������
            if(node->left)qt.push(node->left);
            if(node->right)qt.push(node->right);
        }
        result.push_back(temp);//��ǰ��Ľڵ�洢�ڶ�ά������
    }
    return result;//���ض�ά����
}

/*����һ�Ŷ�����*/
void createBiTree(TreeNode* root)
{
	int val;
    cin>>val;
    if(val==0)//0��ʾ�սڵ�
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
    /*һֱ�ݹ�������ֱ������Ҷ�ӽڵ�*/
    helperInorder(root->left,result);
    /*������Ϊ��ʱ����ʼ��ӡ���ڵ�*/
    result.push_back(root->val);
    /*��ʼ�ݹ���ڵ��������*/
    helperInorder(root->right,result);
}

void helperPostorder(TreeNode* root,vector<int>& result)
{
    if(root==nullptr)return;
    helperPostorder(root->left,result);
    helperPostorder(root->right,result);
    result.push_back(root->val);
}