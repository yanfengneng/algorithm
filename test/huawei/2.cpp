#include <bits/stdc++.h>
using namespace std;

unordered_set<char> dict={'a','e','i','o','u','A','E','I','O','U'};

int main()
{
    string s;
    while(cin>>s){
        int l=0,r=0,n=s.size();
        int res=0;
        while(r<n){
            // �ҵ����һ��Ԫ���ַ�Ԫ�صĺ�һ��λ����ֹ
            while(r<n&&dict.count(s[r]))r++;
            res=max(res,r-l);
            // �������еķ�Ԫ�������ַ�
            while(r<n&&!dict.count(s[r]))r++;
            l=r;
        }
        cout<<res<<endl;
    }
    return 0;
}