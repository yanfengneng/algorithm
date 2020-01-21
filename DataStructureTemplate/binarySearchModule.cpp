#include <iostream>
#include <vector>
using namespace std;

//ģ��1��Ѱ�ҵ���x������λ��
int search_1(vector<int>& nums, int x){
    if(nums.empty())return -1;
    int left=0,right=nums.size()-1;
    //ѭ��������������������û��Ԫ��
    while(left<=right){
        int mid=left+((right-left)>>1);
        if(nums[mid]==x)return mid;//�ҵ�����λ�õ���x��ֱ�ӷ���mid
        else if(nums[mid]>x)right=mid-1;//[mid,right]������Ԫ�ض�����x������������Ҫ��С�ڵ���x�������[left,mid-1]����x
        else left=mid+1;//[left,mid]������Ԫ�ض�С��x������������Ҫ�ڴ��ڵ���x���ұ�����[mid+1,right]����x
    }
    return -1;
}

//ģ��2��Ѱ�Ҵ��ڵ���x����Сֵ��ע����õĴ��ڵ���x��λ��-1����С�ڵ����ֵ
//��ʼ����Ϊ[0,size-1)
//��x�������е�һ��Ԫ�ض�С������x=0,nums=[1,2,2,3]����ôleft��right�����±�0�������������жϴ�ʱ���±��Ƿ������������
//��x�������е����һ��Ԫ�ض��󣬱���x=5,nums=[1,2,2,3]����midָ��3ʱ����ʱ��leftΪmid+1Ϊ����size��ѭ���˳�
//Ҳ���Ǵ�ʱ��right=left=size������ѭ����������������Ҫ�ж�left�Ƿ�Խ�����Ƿ���ڵ���x
//���leftȡֵ��ΧΪ[0,size]����Ϊsize���ʾû���ҵ�λ�ã���Ϊ0��ʾ��һ��Ԫ�ص�λ��Ϊ���ڵ���x����Сֵ
int seach_2(vector<int>& nums,int x){
    int left=0,right=nums.size();
    //ѭ��������������������ֻ��һ��Ԫ��
    while(left<right){
        int mid=left+((right-left)>>1);//����ȡ������left��right���Ϊ1ʱ��right����ȡ��left���������ѭ��
        if(nums[mid]>=x)right=mid;//mid֮���Ԫ�ػ��x������ô�ұ����䲻��������������ȡright=mid��mid���ܾ��Ǵ𰸣���Ҳ������һ����������Ϊ[left,mid]
        else left=mid+1;//mid֮ǰ��Ԫ�ذ���mid����xС����ô��벿�ֲ���������������ȡleft=mid+1��mid��������������Ҳ������һ����������Ϊ[mid+1,right]
    }
    //���ж��ҵ���left�Ƿ���������
    if(left!=nums.size()&&nums[left]==x)return left;
    return -1;
}

//ģ��3��Ѱ��С�ڵ���x�����ֵ
//��ʼ����Ϊ[0,size-1]��ע�ⲻ��ȡ�߽�size����Ϊ����ȡ��mid=sizeʱ���ٷ���nums[mid]�ᷢ������Խ��
//��x�������е�һ��Ԫ�ض�С������x=0,nums=[1,2,2,3]����ôleft��right�����±�0�������������жϴ�ʱ���±��Ƿ������������
//��x�������е����һ��Ԫ�ض��󣬱���x=5,nums=[1,2,2,3]����ôleft��right�����±�Ϊsize-1�������������жϴ�ʱ���±��Ƿ������������
int search_3(vector<int>& nums,int x){
    int left=0,right=nums.size()-1;
    //ѭ��������������������ֻ��һ��Ԫ��
    while(left<right){
        int mid=left+((right-left+1)>>1);//����ȡ������left��right���Ϊ1ʱ��left����ȡ��right�����������ѭ��
        if(nums[mid]<=x)left=mid;//mid֮ǰ��Ԫ�ػ��x��С����ô������䲻��������������ȡleft=mid��mid���ܾ��Ǵ𰸣���Ҳ������һ����������Ϊ[mid,right]
        else right=mid-1;//mid֮���Ԫ�ذ���mid����x����ô�ұ����䲻��������������ȡright=mid-1��mid��������������Ҳ������һ����������Ϊ[left,mid-1]
    }
    //�ж��ҵ���left�Ƿ���������
    if(nums[left]==x)return left;
    return -1;
}

//ģ��4������ģ�壬���leftΪ���ڵ���x����Сֵ��rightΪС��x�����ֵ
//ע�����left��right�ұ�ʱѭ��������Ҳ����(right,left)
int all_search(vector<int>& nums,int x){
    if(nums.empty())return -1;
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+((right-left)>>1);
        if(nums[mid]>=x)right=mid-1;
        else left=mid+1;
    }
    //���ش��ڵ���x����Сֵ
    if(left<nums.size()&&nums[left]==x)return left;
    else return -1;
    //����С��x�����ֵ
    if(right==0)return right;
    else return -1;
}

int main()
{
    vector<int> nums={1,2,2,4};
    cout<<search_3(nums,5)<<endl;
}