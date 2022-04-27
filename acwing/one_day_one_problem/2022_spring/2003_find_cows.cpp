#include <bits/stdc++.h>
using namespace std;

string s;

/*枚举右括号，当右括号的位置确定后，相当于求右括号左侧有多少对左括号*/
int main()
{
    cin>>s;
    // cnt用来记录连续左括号的数量
    int res=0,cnt=0,n=s.size();
    for(int i=1;i<n;++i)
    {
        if(s[i-1]=='('&&s[i]=='(')cnt++;
        else if(s[i-1]==')'&&s[i]==')')res+=cnt;
    }
    cout<<res<<endl;
    return 0;
}