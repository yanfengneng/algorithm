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

// ��[4,5,6]������
void sebsets_backtrack1(vector<int>& a,int start,int n,vector<vector<int>>& res,vector<int>& path)
{
    /*ö���Ӽ�����Ҫʹ�õݹ�߽磬��Ϊstart��nʱ��forѭ��û��Ԫ��ѡ�ˣ��Զ����л���
    ��start=nʱ������forѭ������ȥ��������һ��n-1��Ȼ��path.pop_back���������Զ�������*/
    res.push_back(path);
    /*�����ѡ���б�Ϊ[start,n-1]����ѡ����a[i]�󣬱�ʾ֮ǰ��a[start...i-1]�Ѿ�����Ϊĳ������Ѿ�����ˣ���һ���a[i+1...n-1]��ѡ���Ӽ���
    ��һ��i���±�[0,2]��Χ�ڣ���for��ʼ�����Ļ���ѡ�ĵ��Ӽ�Ϊ[4],[5],[6]�����������һ��ʱ��i֮ǰ��Ԫ���Ƕ�ûѡ�ģ�������һ�������ֻ����[i+1,n-1]֮����±�ѡ��
    Ҳ����˵�ڵݹ����дӱ��������һ��ʱ������ֻѡ��a[i]��Ȼ�������һ�����[i+1,n-1]����ö���Ӽ�������[start,i-1]֮ǰ��Ԫ�ض��������Ӽ���Ϊ���ö����
    ��ÿ��ѡ���б�����i��Ϊ��㣬Ȼ�������[i+1,n-1]��ö�����ģ�������Ϳɿ�����һ��ö�����Ĺ��̣����֮ǰ��Ԫ�ز�ѡ����Ϊ֮ǰ�Ѿ�ѡ���ˣ���Ȼ����ö�����֮��Ԫ��ѡ�벻ѡ��
    ��������ÿ��Ԫ��ѡ�벻ѡ��Ҳ����ö�������Ӽ���������ܹ�2^n���Ӽ�����*/
    for(int i=start;i<n;++i)
    {
        path.push_back(a[i]);
        sebsets_backtrack(a,i+1,n,res,path);
        path.pop_back();
    }
}

// ��ʵ����ö���Ӽ������⣬��ȫ���Ի�һ��д������һ�����
// ���ֻ���ö����ʵ���Ǳ���һ������������ֻ�е���Ҷ�ӽڵ�ʱ�������·������������дӸ��ڵ��ߵ�Ҷ�ӽڵ�(����aΪ��ʱ)��·���������֧��ʾ��ѡ(null)�����ҷ�֧��ʾѡ��
void sebsets_backtrack2(vector<int>& a,int start,int n,vector<vector<int>>& res,vector<int>& path)
{
    if(start==n){res.push_back(path);return;}
    // ��ѡԪ��a[start]
    sebsets_backtrack2(a,start+1,n,res,path);
    // ѡԪ��a[start]
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

// ���Ҳ��ö���Ӽ��Ĺ��̣�ֻ��ɸѡ����Ҫ����Ӽ�
void combine_backtrack(int n,int k,int start,vector<vector<int>>& res,vector<int>& path)
{
    if(path.size()>k)return;
    if(path.size()==k){res.push_back(path);return;}
    // �ò���i���ȡֵ��ʣ��Ԫ�صĸ���������k-path.size()����Ȼ��+1��ʾ��ѡ�����ֵ���
    for(int i=start;i<=n-(k-path.size())+1;++i){
        path.push_back(i);
        combine_backtrack(n,k,i+1,res,path);
        path.pop_back();
    }
}

// ȫ���У���һ��λ����n��ѡ�񣬵ڶ���λ����n-1��ѡ��...
vector<vector<int>> permute(vector<int>& a) {
    int n=a.size();
    bool v[10];
    vector<vector<int>> res;
    vector<int> path;
    backtrace(a,0,n);
    return res;
}

/*�����ѡ���б���pos��v[]����ͬ��¼����pos����ʾ�±�pos���������a[i]�ˣ�ͬʱ��v����¼�±�i�ѱ�ʹ���ˣ������´���ѡ���ʱ����v[]���ų��Ѿ�ѡ����������ˣ�����������Сѡ���б�*/
void permute_backtrace(vector<int>& a,int pos,int n,vector<int>& path,vector<vector<int>>& res,bool* v)
{
    // pos=n��ʾ�±�[0,n-1]������λ�ö��������������
    if(pos==n){res.push_back(path);return;}
    // �����i�ӿ�ʼ0����������v[]����ʾ��ǰ��ѡ���б��Ѿ���С�ˣ����ǽ����ڱ�С��ѡ���б�����ѡ�񼴿�
    // ��һ��λ������vȫ��Ϊfalse�����Ե�һ��λ����n��ѡ�񣻵ڶ���λ��
    for(int i=0;i<n;++i)
    {
        // �±�i�Ѿ���ѡ����ˣ������ڵ�ǰ��ѡ���б�
        if(v[i])continue;
        // ���±�pos��ѡ������a[i]�������v[i]=1����ʾ�±�i�Ա�ѡ��ѡ���б�Ҳ��С��
        path.push_back(a[i]),v[i]=1;
        // ������һ�����ߣ�Ҳ�������±�pos+1�����������С��ѡ���б��е����ּ���
        backtrace(a,pos+1,n);
        // ����ѡ��a[i]����posλ��ɾ��a[i]�������v[i]=0������ԭ֮ǰ��ѡ���б�
        path.pop_back(),v[i]=0;
    }
}

int main()
{

    return 0;
}