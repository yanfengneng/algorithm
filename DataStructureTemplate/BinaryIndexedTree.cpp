#include <iostream>
#include <vector>
using namespace std;

//��״����
class BIT
{
private:
    vector<int> tree;

    // ��ǰx����ܺ�
    int get_sum(int x){
        int sum=0;
        for(int i=x;i;i-=lowbit(i))
            sum+=tree[i];
        return sum;
    }

    // ��λ��x�ϵ�Ԫ������v
    void add(int x,int v){
        for(int i=x;i<tree.size();i+=lowbit(i))
            tree[i]+=v;
    }

    // ����x�Ķ���������ʾ�����λ1��Ӧ��10������
    int lowbit(int x){
        return x&(-x);
    }

public:
    // ��״�����ʼ��
    BIT(vector<int> &a){
        int n=a.size();
        tree.resize(n+1,0);
        // ��״������±�����1��ʼ�洢
        for(int i=0;i<n;++i)
            add(i+1,a[i]);
    }

    int range_sum(int l,int r){
        return get_sum(r+1)-get_sum(l);
    }

    void update(int x,int v){
        add(x,v);
    }
};

int main()
{
    vector<int> nums{1,7,3,0,5,8,3,2,6,2,1,1,4,5};
    BIT bit(nums);
    cout<<bit.range_sum(1,4)<<endl;
    bit.update(2,4);
    cout<<bit.range_sum(1,4)<<endl;
    return 0;
}