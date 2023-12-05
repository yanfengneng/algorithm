#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ̰�ģ�ÿ��ƥ�� groups �е��������� nums �е���ǰλ��
    // ʱ�临�Ӷ����ΪO(n^2)���ռ临�Ӷ�O(1)
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            // ��� nums ��λ�� j ˳��ƥ�� group[i] �Ƿ�ƥ��ɹ�
            // ���ɹ����� j �ƶ� group[i].size �ĳ��ȣ������ɹ�����j����һλ�����Ǵ�j��һ��λ�ÿ�ʼö��
            if(check(groups[i],nums,j)){
                j+=groups[i].size(),i++;
                // group��n�������Ѿ�ƥ�����ˣ���ֱ�ӷ���true
                if(i==groups.size())return true;
            }
            else j++;
        }
        // nums���������ˣ�group��ûƥ���꣬����false
        return false;
    }

    // ����� num �д�λ�� j ��ʼƥ�� g.size �Ƿ�ɹ�
    bool check(vector<int>& group,vector<int>& nums,int j)
    {
        int k=0;
        while(k<group.size()&&j<nums.size()){
            if(group[k]==nums[j])k++,j++;
            else return false;
        }
        if(k==group.size())return true;
        else return false;
    }
};

int main()
{
    vector<vector<int>> groups={{1,-1,-1},{3,-2,0}};
    vector<int> nums={1,-1,0,1,-1,-1,3,-2,0};
    try{
        cout<<Solution().canChoose(groups,nums)<<endl;
    }
    catch(const exception& e){
        cout<<e.what()<<endl;
    }
    return 0;
}