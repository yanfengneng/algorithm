#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //˫ָ�뷨��ָ��iָ��ÿ���ַ���ͬһ��λ�õ��ַ���ָ��j��������ÿ���ַ���
        if(strs.empty())return "";
        else if(strs.size()==1)return strs[0];
        string result="";
        //ȡ��һ���ַ���Ϊ�����ǰ׺��Ȼ�����ÿ���ַ�������ȷ��ʵ�ʵ������ǰ׺
        for(int i=0;i<strs[0].size();++i)//i��ʾָ��ÿ���ַ�����ͬһ��λ�õ��ַ�
        {
            cout<<i<<endl;
            for(int j=1;j<strs.size();++j)//j������ÿ���ַ���
                if(strs[0][i]!=strs[j][i]){
                    cout<<strs[j][i]<<endl;
                    return result;
                }
            result+=strs[0][i];
        }
        return result;
    }
};

int main()
{
    vector<string> strs={"flower","flow","flowig"};
    cout<<Solution().longestCommonPrefix(strs)<<endl;
}