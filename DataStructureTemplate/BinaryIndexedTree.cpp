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
        //��ʼ����״���飬ע���±�0������ǰ׺��
        this->bitArray.resize(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            this->bitArray[i+1]=nums[i];
        }

        for(int i=1;i<this->bitArray.size();++i){
            //��һ������ӵ�һ�����ֿ�ʼ������Ϊ1��2��4��8������������
            //�ڶ��������ʣ��հ״���һ��λ�ÿ�ʼ������Ϊ1��2��4������������
            //��������������ʣ��Ŀհ׵�һ��λ�ÿ�ʼ������Ϊ1������������
            int j=i+(i&-i);
            if(j<this->bitArray.size()){
                this->bitArray[j]+=this->bitArray[i];
            }
        }
    }

    //idx��ʾ�±꣬��delta�ӵ���idx��λ����
    void update(int idx,int delta){
        idx+=1;
        while(idx<this->bitArray.size()){
            this->bitArray[idx]+=delta;
            idx=idx+(idx&-idx);
        }
    }

    //idx��ʾ�±꣬[0,idx]��Χ�ڵ�Ԫ�غͣ���1��Ԫ�ص���(idx+1)��Ԫ�صĺ�
    int prefitSum(int idx){
        idx+=1;
        int result=0;
        while(idx>0){
            result+=this->bitArray[idx];
            idx=idx-(idx&-idx);//
        }
        return result;
    }

    //����[from_idx,to_idx]��Χ�ڵ��������ֺ�
    int rangeSum(int from_idx,int to_idx){
        //[0,to_idx]��Χ��Ԫ�غͼ�ȥ[0,form_idx-1]��Χ�ڵ�Ԫ�غ�
        //����form_idx��1������form_idx����0����1���Ϊ-1�ˣ�Ȼ����prefitsum(-1)Ϊ0
        return prefitSum(to_idx)-prefitSum(from_idx-1);
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