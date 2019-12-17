#include <iostream>
#include <vector>
using namespace std;

//��״����
class BIT
{
private:
    vector<int> bitArray;
public:
    BIT(vector<int>& nums)//���캯����ʼ��
    {
        //ԭʼ����ÿ��Ԫ�ض�Ӧ���±�+1�������������е��±��ˣ�������״�����ԭʼ�����һ������״������±�0��ԭʼ������û�ж�Ӧ�ģ���Ϊ0
        this->bitArray.resize(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            this->bitArray[i+1]=nums[i];
        }

        //j = i + (i & -i)����j < n + 1����bit[j] = bit[j] + bit[i]��������״����
        for(int i=1;i<this->bitArray.size();++i){
            int j=i+(i&-i);
            if(j<this->bitArray.size()){
                this->bitArray[j]+=this->bitArray[i];
            }
        }
    }

    //idx��ʾԭʼ�����е��±꣬idx+1��ʾ��״�����е��±�
    void update(int idx,int delta){
        idx+=1;
        while(idx<this->bitArray.size()){
            this->bitArray[idx]+=delta;
            idx=idx+(idx&-idx);
        }
    }

    //���±�1��ʼ����
    int prefitSum(int idx){
        idx+=1;
        int result=0;
        while(idx>0){
            result+=this->bitArray[idx];
            idx=idx-(idx&-idx);
        }
        return result;
    }

    //����[from_idx,to_idx]��Χ�ڵ��������ֺ�
    int rangeSum(int from_idx,int to_idx){
        return prefitSum(to_idx)-prefitSum(from_idx-1);//��from_idxΪ0ʱ����1��Ϊ-1������prefitsum(-1)Ϊ0
    }
};

int main()
{
    vector<int> nums{1,7,3,0,5,8,3,2,6,2,1,1,4,5};
    BIT bit(nums);
    cout<<bit.prefitSum(4)<<endl;
    cout<<bit.rangeSum(1,4)<<endl;//�±�[1,4]��Χ�ڵ�Ԫ�غ�
    bit.update(4,2);
    cout<<bit.prefitSum(4)<<endl;
}