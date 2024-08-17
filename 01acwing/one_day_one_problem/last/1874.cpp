#include <bits/stdc++.h>
using namespace std;

const int N = 55;
string g[N];
int n,m;
int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

// 寻找所有ABB型的字符串个数
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>g[i];
    // hash记录所有ABB型的字符串以及它所出现的次数
    unordered_map<string,int> hash;
    
    // 开始枚举字符数组中的每个字符，然后让该字符在8个方向中的一个连续走2格，将所得到未越界且未ABB型的字符串进行计数
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            for(int k=0;k<8;++k)// 枚举8个方向
            {
                int x=i,y=j;
                string s(1,g[x][y]);
                // f用来判断是否越界
                bool f=true;
                // 每个方向前进两格
                for(int u=0;u<2;++u)
                {
                    x+=dx[k],y+=dy[k];
                    if(x<0||x>=n||y<0||y>=m)
                    {
                        f=false;
                        break;
                    }
                    s+=g[x][y];
                }
                // 不越界且判断是否为ABB型
                if(f&&s[0]!=s[1]&&s[1]==s[2]&&s[0]!='M'&&s[1]!='O')
                    hash[s]++;
            }
    
    // 遍历寻找所有ABB型字符串的最大次数
    int res=0;
    for(auto [s,cnt]:hash)res=max(cnt,res);
    
    cout<<res<<endl;
    return 0;
}