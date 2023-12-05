#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class BST
{
private:
    /*节点*/
    struct TreeNode
    {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;
private:
   //递归版：搜索节点值
    TreeNode* searchBST_1(TreeNode* root, int val) {
        if(root==nullptr)return root;
        if(root->val==val)return root;
        else if(root->val>val)return searchBST_1(root->left,val);
        else return searchBST_1(root->right,val);
    }
    
    //迭代版：搜索节点值
    TreeNode* searchBST_2(TreeNode* root,int val){
        while(root){
            if(root->val==val)return root;
            else if(val<root->val)root=root->left;
            else root=root->right;
        }
        return nullptr;
    }

    //递归版：插入节点值
    TreeNode* insertIntoBST_1(TreeNode* root, int val) {
        if(root==nullptr)return new TreeNode(val);
        else
        {
            //val的值小于根节点的值，要插在左边，递归直到左边的叶子节点时，将val的节点添加到最左边叶子节点的left节点
            if(val<root->val)root->left=insertIntoBST_1(root->left,val);
            //val的值大于根节点的值，要插在右边，递归直到右边的叶子节点时，将val的节点添加到最右边叶子节点的right节点
            if(val>root->val)root->right=insertIntoBST_1(root->right,val);
        }
        return root;
    }

    //迭代版：插入节点值
    TreeNode* insertIntoBST_2(TreeNode* root,int val){
        if(!root)return new TreeNode(val);
        TreeNode* p=root;
        while(p){
            if(val<p->val){//在左子树中寻找叶子节点进行插入
                if(!p->left){//找到叶子节点，插入到叶子节点后面
                    p->left=new TreeNode(val);
                    return root;
                }
                p=p->left;
            }
            else{//在右子树中寻找叶子节点进行插入
                if(!p->right){//找到叶子节点，插入到叶子节点后面
                    p->right=new TreeNode(val);
                    return root;
                }
                p=p->right;
            }
        }
        return root;
    }

    //第一种方法删除节点：我们将删除节点的右子树连接在其左子树的最右节点上面，然后返回左子树
    TreeNode *deleteNode_1(TreeNode* root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) //找到需要删除的节点
        {
            if (root->left)
            {   //遍历需要删除节点的左子树，找到该左子树的最右边节点，也就是整个左子树中的最大值，然后将删除的节点的右子树连接到最右边节点上，返回左子树
                //这句话的意思是说：我们将需要删除节点的右子树连接在其左子树的最右节点上面，因为右子树的最小值根节点也会大于左子树的最大值（最右节点）
                TreeNode *node = root->left;
                while (node->right)
                    node = node->right;
                node->right = root->right;
                return root->left;
            }
            //左子树为空，直接将右子树节点替换到删除节点上
            return root->right;
        }
        if (root->val > key)
            root->left = deleteNode_1(root->left, key);
        else
            root->right = deleteNode_1(root->right, key);
        return root;
    }

    //第二种删除节点的方法：我们将删除节点的左子树连接在其右子树的最左节点上
    TreeNode *deleteNode_2(TreeNode* root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->right)
            {   //遍历删除节点的右子树，找到该右子树的最左边节点，也就是整个右子树中的最小值，然后将删除节点的左子树连接到最左边节点上，返回右子树
                //因为删除节点左子树的所有节点都小于删除节点，而删除节点的右子树的所有节点都大于删除节点，所以右子树中的最小节点值也会大于左子树中的最大节点值
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

    //中序遍历：得到排序数组
    vector<int> inorderTraversal(TreeNode* root) {
        if(nullptr==root) return {};
        vector<int> result;
        stack<TreeNode*> recond;
        while(!recond.empty()||root!=nullptr)
        {
           if(root!=nullptr)//进栈顺序为根左...根左，出栈顺序为左根...左根
            {
                recond.push(root);
                root=root->left;
            }
            else//直至上一结点的左结点为nullptr时，将上一结点的val打印，并添加其右子树
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
        cout<<"存在1"<<endl;
    }
    else{
        cout<<"存在1"<<endl;
    }
    if(bst.searchBST_2(11)!=nullptr){
        cout<<"存在11"<<endl;
    }
    else{
        cout<<"不存在11"<<endl;
    }
    bst.deleteNode_1(1);
    res=bst.inorderTraversal();
    for(auto& r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    system("pause");
}