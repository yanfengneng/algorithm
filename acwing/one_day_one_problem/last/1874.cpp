#include <bits/stdc++.h>
using namespace std;

const int N = 55;
string g[N];
int n,m;
int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

// Ѱ������ABB�͵��ַ�������
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>g[i];
    // hash��¼����ABB�͵��ַ����Լ��������ֵĴ���
    unordered_map<string,int> hash;
    
    // ��ʼö���ַ������е�ÿ���ַ���Ȼ���ø��ַ���8�������е�һ��������2�񣬽����õ�δԽ����δABB�͵��ַ������м���
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            for(int k=0;k<8;++k)// ö��8������
            {
                int x=i,y=j;
                string s(1,g[x][y]);
                // f�����ж��Ƿ�Խ��
                bool f=true;
                // ÿ������ǰ������
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
                // ��Խ�����ж��Ƿ�ΪABB��
                if(f&&s[0]!=s[1]&&s[1]==s[2]&&s[0]!='M'&&s[1]!='O')
                    hash[s]++;
            }
    
    // ����Ѱ������ABB���ַ�����������
    int res=0;
    for(auto [s,cnt]:hash)res=max(cnt,res);
    
    cout<<res<<endl;
    return 0;
}