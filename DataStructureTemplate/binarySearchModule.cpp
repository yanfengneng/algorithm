#include <iostream>
#include <vector>
using namespace std;

//模板1：寻找等于x的任意位置
int search_1(vector<int>& nums, int x){
    if(nums.empty())return -1;
    int left=0,right=nums.size()-1;
    //循环结束的条件：区间内没有元素
    while(left<=right){
        int mid=left+((right-left)>>1);
        if(nums[mid]==x)return mid;//找到任意位置等于x，直接返回mid
        else if(nums[mid]>x)right=mid-1;//[mid,right]的所有元素都大于x，所以我们需要在小于等于x左边区间[left,mid-1]搜索x
        else left=mid+1;//[left,mid]的所有元素都小于x，所以我们需要在大于等于x的右边区间[mid+1,right]搜索x
    }
    return -1;
}

//模板2：寻找大于等于x的最小值，注将求得的大于等于x的位置-1就是小于的最大值
//初始区间为[0,size-1)
//若x比数组中第一个元素都小，比如x=0,nums=[1,2,2,3]，那么left与right会在下标0处相遇，我们判断此时的下标是否满足情况即可
//若x比数组中的最后一个元素都大，比如x=5,nums=[1,2,2,3]，当mid指向3时，此时的left为mid+1为等于size，循环退出
//也就是此时的right=left=size，所以循环结束后我们任需要判断left是否越界且是否大于等于x
//最后left取值范围为[0,size]，若为size则表示没有找到位置，若为0表示第一个元素的位置为大于等于x的最小值
int seach_2(vector<int>& nums,int x){
    int left=0,right=nums.size();
    //循环结束的条件：区间内只有一个元素
    while(left<right){
        int mid=left+((right-left)>>1);//向下取整，在left与right相差为1时，right可以取到left不会造成死循环
        if(nums[mid]>=x)right=mid;//mid之后的元素会比x更大，那么右边区间不满足条件，所以取right=mid（mid可能就是答案），也就是下一次搜索区间为[left,mid]
        else left=mid+1;//mid之前的元素包括mid都比x小，那么左半部分不满足条件，所以取left=mid+1（mid不满足条件），也就是下一次搜索区间为[mid+1,right]
    }
    //需判断找到的left是否满足条件
    if(left!=nums.size()&&nums[left]==x)return left;
    return -1;
}

//模板3：寻找小于等于x的最大值
//初始区间为[0,size-1]，注意不能取边界size是因为向上取整mid=size时，再访问nums[mid]会发生数组越界
//若x比数组中第一个元素都小，比如x=0,nums=[1,2,2,3]，那么left与right会在下标0处相遇，我们判断此时的下标是否满足情况即可
//若x比数组中的最后一个元素都大，比如x=5,nums=[1,2,2,3]，那么left与right会在下标为size-1处相遇，我们判断此时的下标是否满足情况即可
int search_3(vector<int>& nums,int x){
    int left=0,right=nums.size()-1;
    //循环结束的条件：区间内只有一个元素
    while(left<right){
        int mid=left+((right-left+1)>>1);//向上取整，在left与right相差为1时，left可以取到right而不会造成死循环
        if(nums[mid]<=x)left=mid;//mid之前的元素会比x更小，那么左边区间不满足条件，所以取left=mid（mid可能就是答案），也就是下一次搜索区间为[mid,right]
        else right=mid-1;//mid之后的元素包括mid都比x大，那么右边区间不满足条件，所以取right=mid-1（mid不满足条件），也就是下一次搜索区间为[left,mid-1]
    }
    //判断找到的left是否满足条件
    if(nums[left]==x)return left;
    return -1;
}

//模板4：万能模板，最后left为大于等于x的最小值，right为小于x的最大值
//注：最后left在right右边时循环结束，也就是(right,left)
int all_search(vector<int>& nums,int x){
    if(nums.empty())return -1;
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+((right-left)>>1);
        if(nums[mid]>=x)right=mid-1;
        else left=mid+1;
    }
    //返回大于等于x的最小值
    if(left<nums.size()&&nums[left]==x)return left;
    else return -1;
    //返回小于x的最大值
    if(right==0)return right;
    else return -1;
}

int main()
{
    vector<int> nums={1,2,2,4};
    cout<<search_3(nums,5)<<endl;
}