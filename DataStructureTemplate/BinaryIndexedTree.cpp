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
        //初始化树状数组，注意下标0不计算前缀和
        this->bitArray.resize(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            this->bitArray[i+1]=nums[i];
        }

        for(int i=1;i<this->bitArray.size();++i){
            //第一层就填充从第一个数字开始，长度为1，2，4，8的区间的区间和
            //第二层就填充从剩余空白处第一个位置开始，长度为1，2，4的区间的区间和
            //第三层就填充从最后剩余的空白第一个位置开始，长度为1的区间的区间和
            int j=i+(i&-i);
            if(j<this->bitArray.size()){
                this->bitArray[j]+=this->bitArray[i];
            }
        }
    }

    //idx表示下标，将delta加到第idx个位置上
    void update(int idx,int delta){
        idx+=1;
        while(idx<this->bitArray.size()){
            this->bitArray[idx]+=delta;
            idx=idx+(idx&-idx);
        }
    }

    //idx表示下标，[0,idx]范围内的元素和，第1个元素到第(idx+1)个元素的和
    int prefitSum(int idx){
        idx+=1;
        int result=0;
        while(idx>0){
            result+=this->bitArray[idx];
            idx=idx-(idx&-idx);//
        }
        return result;
    }

    //返回[from_idx,to_idx]范围内的所有数字和
    int rangeSum(int from_idx,int to_idx){
        //[0,to_idx]范围内元素和减去[0,form_idx-1]范围内的元素和
        //这里form_idx减1，比如form_idx等于0，减1后变为-1了，然后算prefitsum(-1)为0
        return prefitSum(to_idx)-prefitSum(from_idx-1);
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