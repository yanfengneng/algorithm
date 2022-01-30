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
    randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
    randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    cout<<randomizedSet.getRandom()<<endl; // getRandom 应随机返回 1 或 2 。
    randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
    cout<<randomizedSet.getRandom()<<endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}