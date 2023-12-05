#include <iostream>
#include <vector>

using namespace std;

// 由于数据长度为50000，会爆int，因此要用long long
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
        // 数组中仅有一个元素或没有元素时，归并结束
        if(l>=r)return 0;
        // 1、确定分界点
        int mid=(l+r)>>1;
        // 2、进行递归排序，类试树的后序遍历，左右根
        LL res=memge_sort(nums,l,mid)+memge_sort(nums,mid+1,r);
        // 3、进行归并--合二为一
        int k=0,i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(nums[i]<=nums[j])tmp[k++]=nums[i++];
            else{
                tmp[k++]=nums[j++];
                // nums[i]>nums[j]，那么nums[i~mid]都比nums[j]要大，都会构成逆序对
                res+=mid-i+1;
            }
        }
        // 4、进行扫尾工作，剩下的部分添加到tmp中
        while(i<=mid)tmp[k++]=nums[i++];
        while(j<=r)tmp[k++]=nums[j++];
        // 5、进行还原nums
        for(int i=l,j=0;i<=r;i++,j++)nums[i]=tmp[j];
        
        return res;
    }
};

int main()
{
    vector<int> nums={};
    //cout<<Solution().reversePairs(nums)<<endl;
    cout<<nums.size()-1<<endl;// 直接输出-1对应的补码的十进制数
    int i=nums.size()-1;// 强制类型转换为int了，不是无符号数了
    cout<<i<<endl;
}