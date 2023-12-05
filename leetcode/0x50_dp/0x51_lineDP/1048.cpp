#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ת��Ϊ LIS ����
    int longestStrChain(vector<string>& ws) {
         // �����Ƚ�����С���������
        sort(ws.begin(),ws.end(),[](const auto& a,const auto& b){
            return a.size()<b.size();
        });
        int n=ws.size();
        // f[i]��ʾ��ws[i]��β����������ȣ���ʼֵΪ1����ʾÿ���������й���һ������Ϊ1�ĳ���
        vector<int> f(n,1);
        int res=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
                if(check(ws[j],ws[i])){
                    f[i]=max(f[i],f[j]+1);
                    res=max(res,f[i]);
                }
        return res;
    }

    // ʹ��˫ָ���ж�a�Ƿ�Ϊb��������
    bool check(const string& a,const string &b){
        int m=a.size(),n=b.size();
        int i=0,j=0;
        while(i<m&&j<n){
            if(a[i]==b[j])i++;
            j++;
        }
        return i==m;
    }
};

int main()
{
    vector<string> ws={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout<<Solution().longestStrChain(ws)<<endl;
    return 0;
}