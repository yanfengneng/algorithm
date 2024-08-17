#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> a)
{
    vector<vector<int>> res;
    vector<int> path;
    int n=a.size();
    subsets_backtrack(a,0,n,res,path);
    return res;
}

// 用[4,5,6]来举例
void sebsets_backtrack1(vector<int>& a,int start,int n,vector<vector<int>>& res,vector<int>& path)
{
    /*枚举子集不需要使用递归边界，因为start到n时，for循环没有元素选了，自动进行回溯
    若start=n时，本层for循环进不去，返回上一层n-1，然后path.pop_back，这样就自动回溯了*/
    res.push_back(path);
    /*本层的选择列表为[start,n-1]，在选择了a[i]后，表示之前的a[start...i-1]已经被作为某个起点已经添加了，下一层从a[i+1...n-1]中选择子集；
    第一层i在下标[0,2]范围内，从for开始遍历的话可选的单子集为[4],[5],[6]，本层进入下一层时，i之前的元素是都没选的，进入下一层后，我们只能在[i+1,n-1]之间的下标选；
    也就是说在递归树中从本层进入下一层时，我们只选择a[i]，然后进入下一层后在[i+1,n-1]继续枚举子集，至于[start,i-1]之前的元素都被其他子集作为起点枚举了
    即每次选择列表都是以i作为起点，然后继续在[i+1,n-1]中枚举起点的，所以这就可看作是一个枚举起点的过程，起点之前的元素不选（因为之前已经选过了），然后再枚举起点之后元素选与不选，
    这样就是每个元素选与不选，也就是枚举所有子集的情况，总共2^n中子集个数*/
    for(int i=start;i<n;++i)
    {
        path.push_back(a[i]);
        sebsets_backtrack(a,i+1,n,res,path);
        path.pop_back();
    }
}

// 其实这种枚举子集的问题，完全可以换一种写法，换一种理解
// 这种回溯枚举其实就是遍历一颗满二叉树，只有到达叶子节点时，才添加路径，即添加所有从根节点走到叶子节点(数组a为空时)的路径，走左分支表示不选(null)，走右分支表示选择。
void sebsets_backtrack2(vector<int>& a,int start,int n,vector<vector<int>>& res,vector<int>& path)
{
    if(start==n){res.push_back(path);return;}
    // 不选元素a[start]
    sebsets_backtrack2(a,start+1,n,res,path);
    // 选元素a[start]
    path.push_back(a[start]);
    sebsets_backtrack2(a,start+1,n,res,path);
    path.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    combine_backtrack(n,k,1,res,path);
    return res;
}

// 组合也是枚举子集的过程，只是筛选符合要求的子集
void combine_backtrack(int n,int k,int start,vector<vector<int>>& res,vector<int>& path)
{
    if(path.size()>k)return;
    if(path.size()==k){res.push_back(path);return;}
    // 该层内i最大取值中剩余元素的个数至少有k-path.size()个，然后+1表示可选的最大值序号
    for(int i=start;i<=n-(k-path.size())+1;++i){
        path.push_back(i);
        combine_backtrack(n,k,i+1,res,path);
        path.pop_back();
    }
}

// 全排列，第一个位置有n种选择，第二个位置有n-1种选择...
vector<vector<int>> permute(vector<int>& a) {
    int n=a.size();
    bool v[10];
    vector<vector<int>> res;
    vector<int> path;
    backtrace(a,0,n);
    return res;
}

/*这里的选择列表用pos和v[]来共同记录，用pos来表示下标pos处填充数字a[i]了，同时用v来记录下标i已被使用了，这样下次做选择的时候，用v[]来排除已经选择过的数字了，这样用来缩小选择列表*/
void permute_backtrace(vector<int>& a,int pos,int n,vector<int>& path,vector<vector<int>>& res,bool* v)
{
    // pos=n表示下标[0,n-1]的所有位置都被填充了数字了
    if(pos==n){res.push_back(path);return;}
    // 这里的i从开始0遍历，采用v[]来表示当前的选择列表已经变小了，我们仅需在变小的选择列表中做选择即可
    // 第一个位置由于v全部为false，所以第一个位置有n种选择；第二个位置
    for(int i=0;i<n;++i)
    {
        // 下标i已经被选择过了，不属于当前的选择列表
        if(v[i])continue;
        // 在下标pos处选择数字a[i]，并标记v[i]=1来表示下标i以被选择，选择列表也变小了
        path.push_back(a[i]),v[i]=1;
        // 进入下一步决策，也就是在下标pos+1除填充现已缩小的选择列表中的数字即可
        backtrace(a,pos+1,n);
        // 撤销选择a[i]，在pos位置删掉a[i]，并标记v[i]=0，来还原之前的选择列表
        path.pop_back(),v[i]=0;
    }
}

int main()
{

    return 0;
}