#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    //�ⷨ1����̬�滮
    string longestPalindrome_1(string s) {
        if(s.size()<2)return s;
        
        //dp[i][j]��ʾs[i]��s[j]�Ƿ�Ϊ���Ĵ�����Ϊ1������Ϊ0
        int size=s.size(),dp[size][size];
        memset(dp,0,sizeof(dp));
        
        int max=1,start=0;
        
        //��ʼ���߽�ֵ
        for(int i=0;i<size;++i){
            dp[i][i]=1;
            if(i<size-1&&s[i]==s[i+1]){
                dp[i][i+1]=1;//�ǻ��Ĵ�����ʾΪ1
                max=2;
                start=i;
            }
        }
        
        for(int l=3;l<=size;l++)//l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
        {
            for(int i=0;i+l-1<size;i++)
            {
                int j=l+i-1;//��ֹ�ַ�λ��
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//״̬ת��
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);
    }
    
    //�ⷨ2���������㷨
    string longestPalindrome_2(string s)
    {
        string t="$#";
        for(auto c:s){
            t+=c;
            t+='#';
        }
        
        vector<int> p(t.size(),0);
        
        //mx��ʾĳ�����Ĵ����������Ҷ˰뾶���±꣬id��ʾ��������Ӵ����м�λ���±�
        //resLen��ʾ��Ӧ��s�е�����ӻ��Ĵ��İ뾶��resCenter��ʾ����ӻ��Ĵ����м�λ��
        int mx=0,id=0,resLen=0,resCenter=0;
        
        for(int i=1;i<t.size();++i)
        {
            p[i]=mx>i?min(p[2*id-i],mx-i):1;
            
            //��������������������Ҫ����������չ��
            while(t[i+p[i]]==t[i-p[i]])p[i]++;
            
            //�뾶�±�i+p[i]�����߽�mx����Ҫ����
            if(mx<i+p[i]){
                mx=i+p[i];
                id=i;
            }
            
            //�����������Ӵ�����Ϣ���뾶���м�λ��
            if(resLen<p[i]){
                resLen=p[i];
                resCenter=i;
            }
        }
        
        //������Ӵ�����Ϊ�뾶-1����ʼλ��Ϊ�м�λ�ü�ȥ�뾶�ٳ���2
        return s.substr((resCenter-resLen)/2,resLen-1);
    }
    
    //�ⷨ3��������չ��
    string longestPalindrome(string s){
        if(s.size()<2)return s;
        
        //���Ĵ�����ʼ����ֹλ���Լ������Ĵ��ĳ���
        int start=0,end=0,mLen=0;
        
        for(int i=0;i<s.size();++i)
        {
            int len1=expand(s,i,i);//��iΪ������������չ
            int len2=expand(s,i,i+1);//������Ԫ��Ϊ������������չ
            
            mLen=max(max(len1,len2),mLen);//���������Ĵ�����
            
            if(mLen>end-start+1){//���»��Ĵ�����ʼ����ֹλ��
                start=i-(mLen-1)/2;
                end=i+mLen/2;
            }
        }
        return s.substr(start,mLen);
    }
    
private:
    int expand(string s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;//0 ��Ϊ -1
            right++;//0 ��Ϊ 1
        }
        return right-left-1;//1+1-1=1
    }
};

int main()
{
    cout<<Solution().longestPalindrome("babad")<<endl;
    cout<<Solution().longestPalindrome("12211")<<endl;
    system("pause");
}