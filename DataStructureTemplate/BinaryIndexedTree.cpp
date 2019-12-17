#include <iostream>
#include <vector>
using namespace std;

//树状数组
class BIT
{
private:
    vector<int> bitArray;
public:
    BIT(vector<int>& nums)//构造函数初始化
    {
        //原始数组每个元素对应的下标+1就是数组数组中的下标了，所以树状数组比原始数组多一个，树状数组的下标0在原始数组中没有对应的，设为0
        this->bitArray.resize(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            this->bitArray[i+1]=nums[i];
        }

        //j = i + (i & -i)，若j < n + 1，则bit[j] = bit[j] + bit[i]，建立树状数组
        for(int i=1;i<this->bitArray.size();++i){
            int j=i+(i&-i);
            if(j<this->bitArray.size()){
                this->bitArray[j]+=this->bitArray[i];
            }
        }
    }

    //idx表示原始数组中的下标，idx+1表示树状数组中的下标
    void update(int idx,int delta){
        idx+=1;
        while(idx<this->bitArray.size()){
            this->bitArray[idx]+=delta;
            idx=idx+(idx&-idx);
        }
    }

    //从下标1开始计算
    int prefitSum(int idx){
        idx+=1;
        int result=0;
        while(idx>0){
            result+=this->bitArray[idx];
            idx=idx-(idx&-idx);
        }
        return result;
    }

    //返回[from_idx,to_idx]范围内的所有数字和
    int rangeSum(int from_idx,int to_idx){
        return prefitSum(to_idx)-prefitSum(from_idx-1);//当from_idx为0时，减1后为-1，计算prefitsum(-1)为0
    }
};

int main()
{
    vector<int> nums{1,7,3,0,5,8,3,2,6,2,1,1,4,5};
    BIT bit(nums);
    cout<<bit.prefitSum(4)<<endl;
    cout<<bit.rangeSum(1,4)<<endl;//下标[1,4]范围内的元素和
    bit.update(4,2);
    cout<<bit.prefitSum(4)<<endl;
}