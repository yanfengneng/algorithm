#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        // ��flag����¼�Ƿ�ǰ�����b���������aʱ����ǰ�����b��ֱ�ӷ���false
        bool flag=false;
        for(char ch:s){
            if(ch=='a')
                if(flag)return false;
            else flag=true;
        }
        return true;
    }
};

int main()
{
    cout<<Solution().checkString("aaabbb")<<endl;
    return 0;
}