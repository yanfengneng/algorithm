#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //˼·��������ת��Ϊ�ַ�����Ȼ����ǰ��������Ѱ�ұ��±�i���ִ�����������±�index��Ȼ�󽻻��������±�����Ӧ�����־͵õ����Ľ����
    int maximumSwap(int num) {
        if(num<10)return num;
        string s=to_string(num);
        for(int i=0;i<s.size();++i){
            int index=i;
            for(int j=i+1;j<s.size();++j){
                if(s[j]>=s[index])index=j;//index�Ǳ��±�i������������±꣬��̬���µ�
            }
            if(index!=i&&s[index]!=s[i]){//ֻ��Ҫ����һ�Σ��͵õ��������
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