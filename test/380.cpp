#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    set<int> record;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(record.count(val))return false;
        else{
            record.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(record.count(val)){
            record.erase(val);
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int n=record.size();
        return *next(record.begin(),rand()%n);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet randomizedSet;
    randomizedSet.insert(1); // �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
    randomizedSet.remove(2); // ���� false ����ʾ�����в����� 2 ��
    randomizedSet.insert(2); // �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
    cout<<randomizedSet.getRandom()<<endl; // getRandom Ӧ������� 1 �� 2 ��
    randomizedSet.remove(1); // �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
    randomizedSet.insert(2); // 2 ���ڼ����У����Է��� false ��
    cout<<randomizedSet.getRandom()<<endl; // ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
}