#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e5;
int f[N],f2[N][N];
class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        return dp2(a);
    }

    // ���µ��Ͻ���״̬ת��
    int dp1(vector<vector<int>>& a)
    {
        int n=a.size();
        memset(f,0,sizeof f);
        // ��ʼ�����һ�е�״̬
        for(int i=0;i<a.back().size();++i)f[i]=a[n-1][i];
        // �ӵ����ڶ��п�ʼ����״̬ת��
        /*for(int i=n-2;i>=0;i--)
            for(int j=0;j<=i;++j)
                 f[i][j]=min(f[i+1][j],f[i+1][j+1])+a[i][j];
        */
        // Ҳ���Խ��пռ��Ż�������i�ǴӴ�С����ö�ٵģ�����״̬ת���е�f[j],f[j+1]�ǵ�i+1�е�����
        // j����Ҳ�Ǵ�С�������ö�ٵģ�����j+1Ҳ�ǵ�i+1���е�����
        for(int i=n-2;i>=0;--i)
            for(int j=0;j<=i;++j)
                f[j]=min(f[j],f[j+1])+a[i][j];
        return f[0];
    }

    // ���ϵ��½���״̬ת��
    int dp2(vector<vector<int>>& a)
    {
        int n=a.size();
        memset(f2,0x3f,sizeof f2);
        f2[0][0]=a[0][0];
        for(int i=1;i<n;++i)
            for(int j=0;j<=i;++j)
                // �߽�������⴦��
                if(j==0)f2[i][j]=f2[i-1][j]+a[i][j];
                else if(j==i)f2[i][j]=f2[i-1][j-1]+a[i][j];
                else f2[i][j]=min(f2[i-1][j],f2[i-1][j-1])+a[i][j];
        
        int res=INF;
        for(int i=0;i<n;++i)res=min(res,f2[n-1][i]);
        return res;
    }
};

int main()
{
    vector<vector<int>> t={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumTotal(t)<<endl;
    return 0;
}