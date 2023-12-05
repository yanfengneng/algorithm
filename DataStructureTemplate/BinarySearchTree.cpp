#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class BST
{
private:
    /*�ڵ�*/
    struct TreeNode
    {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;
private:
   //�ݹ�棺�����ڵ�ֵ
    TreeNode* searchBST_1(TreeNode* root, int val) {
        if(root==nullptr)return root;
        if(root->val==val)return root;
        else if(root->val>val)return searchBST_1(root->left,val);
        else return searchBST_1(root->right,val);
    }
    
    //�����棺�����ڵ�ֵ
    TreeNode* searchBST_2(TreeNode* root,int val){
        while(root){
            if(root->val==val)return root;
            else if(val<root->val)root=root->left;
            else root=root->right;
        }
        return nullptr;
    }

    //�ݹ�棺����ڵ�ֵ
    TreeNode* insertIntoBST_1(TreeNode* root, int val) {
        if(root==nullptr)return new TreeNode(val);
        else
        {
            //val��ֵС�ڸ��ڵ��ֵ��Ҫ������ߣ��ݹ�ֱ����ߵ�Ҷ�ӽڵ�ʱ����val�Ľڵ���ӵ������Ҷ�ӽڵ��left�ڵ�
            if(val<root->val)root->left=insertIntoBST_1(root->left,val);
            //val��ֵ���ڸ��ڵ��ֵ��Ҫ�����ұߣ��ݹ�ֱ���ұߵ�Ҷ�ӽڵ�ʱ����val�Ľڵ���ӵ����ұ�Ҷ�ӽڵ��right�ڵ�
            if(val>root->val)root->right=insertIntoBST_1(root->right,val);
        }
        return root;
    }

    //�����棺����ڵ�ֵ
    TreeNode* insertIntoBST_2(TreeNode* root,int val){
        if(!root)return new TreeNode(val);
        TreeNode* p=root;
        while(p){
            if(val<p->val){//����������Ѱ��Ҷ�ӽڵ���в���
                if(!p->left){//�ҵ�Ҷ�ӽڵ㣬���뵽Ҷ�ӽڵ����
                    p->left=new TreeNode(val);
                    return root;
                }
                p=p->left;
            }
            else{//����������Ѱ��Ҷ�ӽڵ���в���
                if(!p->right){//�ҵ�Ҷ�ӽڵ㣬���뵽Ҷ�ӽڵ����
                    p->right=new TreeNode(val);
                    return root;
                }
                p=p->right;
            }
        }
        return root;
    }

    //��һ�ַ���ɾ���ڵ㣺���ǽ�ɾ���ڵ���������������������������ҽڵ����棬Ȼ�󷵻�������
    TreeNode *deleteNode_1(TreeNode* root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) //�ҵ���Ҫɾ���Ľڵ�
        {
            if (root->left)
            {   //������Ҫɾ���ڵ�����������ҵ��������������ұ߽ڵ㣬Ҳ���������������е����ֵ��Ȼ��ɾ���Ľڵ�����������ӵ����ұ߽ڵ��ϣ�����������
                //��仰����˼��˵�����ǽ���Ҫɾ���ڵ���������������������������ҽڵ����棬��Ϊ����������Сֵ���ڵ�Ҳ����������������ֵ�����ҽڵ㣩
                TreeNode *node = root->left;
                while (node->right)
                    node = node->right;
                node->right = root->right;
                return root->left;
            }
            //������Ϊ�գ�ֱ�ӽ��������ڵ��滻��ɾ���ڵ���
            return root->right;
        }
        if (root->val > key)
            root->left = deleteNode_1(root->left, key);
        else
            root->right = deleteNode_1(root->right, key);
        return root;
    }

    //�ڶ���ɾ���ڵ�ķ��������ǽ�ɾ���ڵ����������������������������ڵ���
    TreeNode *deleteNode_2(TreeNode* root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->right)
            {   //����ɾ���ڵ�����������ҵ���������������߽ڵ㣬Ҳ���������������е���Сֵ��Ȼ��ɾ���ڵ�����������ӵ�����߽ڵ��ϣ�����������
                //��Ϊɾ���ڵ������������нڵ㶼С��ɾ���ڵ㣬��ɾ���ڵ�������������нڵ㶼����ɾ���ڵ㣬�����������е���С�ڵ�ֵҲ������������е����ڵ�ֵ
                TreeNode *node = root->right;
                while (node->left)
                    node = node->left;
                node->left = root->left;
                return root->right;
            }
            return root->left;
        }
        if (root->val > key)
            root->left = deleteNode_2(root->left, key);
        else
            root->right = deleteNode_2(root->right, key);
        return root;
    }

    //����������õ���������
    vector<int> inorderTraversal(TreeNode* root) {
        if(nullptr==root) return {};
        vector<int> result;
        stack<TreeNode*> recond;
        while(!recond.empty()||root!=nullptr)
        {
           if(root!=nullptr)//��ջ˳��Ϊ����...���󣬳�ջ˳��Ϊ���...���
            {
                recond.push(root);
                root=root->left;
            }
            else//ֱ����һ��������Ϊnullptrʱ������һ����val��ӡ���������������
            {
                TreeNode* top=recond.top();recond.pop();
                result.push_back(top->val);
                root=top->right;
            }
        }
        return result;
    }
public:
    BST():root(nullptr){}

    TreeNode* searchBST_1(int val){
        return searchBST_1(root,val);
    }
    TreeNode* searchBST_2(int val){
        return searchBST_2(root,val);
    }

    TreeNode* insertIntoBST_1(int val){
        root=insertIntoBST_1(root,val);
        return root;
    }

    TreeNode* insertIntoBST_2(int val){
        root=insertIntoBST_2(root,val);
        return root;
    }

    TreeNode* deleteNode_1(int key){
        root=deleteNode_1(root,key);
        return root;
    }

    TreeNode* deleteNode_2(int key){
        root=deleteNode_2(root,key);
        return root;
    }

    vector<int> inorderTraversal(){
        return inorderTraversal(root);
    }
};

int main()
{
    BST bst;
    vector<int> nums={10,8,6,4,2,1,3,5,7};
    for(int& num:nums){
        bst.insertIntoBST_1(num);
    }
    vector<int> res=bst.inorderTraversal();
    for(auto& r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    if(bst.searchBST_1(1)!=nullptr){
        cout<<"����1"<<endl;
    }
    else{
        cout<<"����1"<<endl;
    }
    if(bst.searchBST_2(11)!=nullptr){
        cout<<"����11"<<endl;
    }
    else{
        cout<<"������11"<<endl;
    }
    bst.deleteNode_1(1);
    res=bst.inorderTraversal();
    for(auto& r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    system("pause");
}