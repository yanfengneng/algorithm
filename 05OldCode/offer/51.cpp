#include <iostream>
#include <vector>

using namespace std;

// �������ݳ���Ϊ50000���ᱬint�����Ҫ��long long
typedef long long LL;

class Solution {
private:
    vector<int> tmp;
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int n=nums.size();
        tmp.resize(n);
        return memge_sort(nums,0,n-1);
    }

    LL memge_sort(vector<int>& nums,int l,int r)
    {
        // �����н���һ��Ԫ�ػ�û��Ԫ��ʱ���鲢����
        if(l>=r)return 0;
        // 1��ȷ���ֽ��
        int mid=(l+r)>>1;
        // 2�����еݹ������������ĺ�����������Ҹ�
        LL res=memge_sort(nums,l,mid)+memge_sort(nums,mid+1,r);
        // 3�����й鲢--�϶�Ϊһ
        int k=0,i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(nums[i]<=nums[j])tmp[k++]=nums[i++];
            else{
                tmp[k++]=nums[j++];
                // nums[i]>nums[j]����ônums[i~mid]����nums[j]Ҫ�󣬶��ṹ�������
                res+=mid-i+1;
            }
        }
        // 4������ɨβ������ʣ�µĲ�����ӵ�tmp��
        while(i<=mid)tmp[k++]=nums[i++];
        while(j<=r)tmp[k++]=nums[j++];
        // 5�����л�ԭnums
        for(int i=l,j=0;i<=r;i++,j++)nums[i]=tmp[j];
        
        return res;
    }
};

int main()
{
    vector<int> nums={};
    //cout<<Solution().reversePairs(nums)<<endl;
    cout<<nums.size()-1<<endl;// ֱ�����-1��Ӧ�Ĳ����ʮ������
    int i=nums.size()-1;// ǿ������ת��Ϊint�ˣ������޷�������
    cout<<i<<endl;
}