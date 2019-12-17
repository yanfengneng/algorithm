#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //思路：将数字转换为字符串，然后由前向后遍历，寻找比下标i数字大的最大的数字下标index，然后交换这两个下标所对应的数字就得到最后的结果了
    int maximumSwap(int num) {
        if(num<10)return num;
        string s=to_string(num);
        for(int i=0;i<s.size();++i){
            int index=i;
            for(int j=i+1;j<s.size();++j){
                if(s[j]>=s[index])index=j;//index是比下标i大的最大的数字下标，动态更新的
            }
            if(index!=i&&s[index]!=s[i]){//只需要交换一次，就得到最后结果了
                swap(s[i],s[index]);
                break;
            }
        }
        return stoi(s);
    }
};

int main()
{
    cout<<Solution().maximumSwap(87621354)<<endl;
    system("pause");
}