#include <bits/stdc++.h>
using namespace std;

string s;

/*ö�������ţ��������ŵ�λ��ȷ�����൱��������������ж��ٶ�������*/
int main()
{
    cin>>s;
    // cnt������¼���������ŵ�����
    int res=0,cnt=0,n=s.size();
    for(int i=1;i<n;++i)
    {
        if(s[i-1]=='('&&s[i]=='(')cnt++;
        else if(s[i-1]==')'&&s[i]==')')res+=cnt;
    }
    cout<<res<<endl;
    return 0;
}