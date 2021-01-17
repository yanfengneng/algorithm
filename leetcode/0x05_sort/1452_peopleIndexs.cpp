#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // �������ݷ�Χ��С��100*100*500=5e6�����ᳬʱ
    // ��⣺��������ʱ�临�Ӷ�O(N^2 * m)���ռ临�Ӷ�O(1)
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<int> res;
        // ��ÿ���û��ղ��嵥��Ĺ�ʽ����ĸ����
        for(auto &item:f)sort(item.begin(),item.end());
        int n=f.size();

        // ���б���ö��
        for(int i=0;i<n;++i)
        {
            bool isSubset=false;
            for(int j=0;j<n;++j)
            {
                // ��i���û��ǵ�j���û����Ӽ�����ֱ��break
                // includes���ж��Ӽ���һ���⺯������C++17��������
                if(i!=j&&includes(f[j].begin(),f[j].end(),f[i].begin(),f[i].end()))
                {
                    isSubset=true;
                    break;
                }
            }
            // ��i���û������κε��Ӽ��������i
            if(!isSubset)res.push_back(i);
        }

        return res;
    }
};

int main()
{
    vector<vector<string>> f({{"leetcode","google","facebook"},
    {"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}});
    auto res=Solution().peopleIndexes(f);
    for(auto r:res)cout<<r<<" ";
    cout<<endl;
    return 0;
}