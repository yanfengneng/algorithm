#include <iostream>
#include <cstring>
using namespace std;
#define INT 100000000

char g[10][10];
// �������飬5�������С��ϡ��ҡ��¡���
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};

// ת�俪��
void turn(int x,int y)
{
    for(int i=0;i<5;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        // g[a][b]��ֵ���иı䣬��1��Ϊ0��0��Ϊ1
        if(a>=0&&a<5&&b>=0&&b<5)
        {
            // g[a][b]='0'+('1'-g[a][b]);
            g[a][b]^=1;// ���������һ���ģ�0���1��1���0
        }
    }
}

int work()
{
    int ans=INT;
    // ��һ����32��ö�ٷ�����ö��0-31����ʹ��һ��5λ��������������
    for(int k=0;k<1<<5;++k)
    {
        // res������¼���ƵĴ���
        int res=0;
        char backup[10][10];// ����Ҫö��ÿ��״̬������Ҫ��������
        memcpy(backup,g,sizeof g);
        // ��ɵ�һ�е�ö�ٺ󣬾͹̶���һ��
        for(int j=0;j<5;++j)
            if(k>>j&1)// ��jλ��ѡȡ�ˣ���Ҫturnһ��
            {
                res++;
                turn(0,j);// 0��j��
            }
        
        // ��һ���Ѿ��̶��ˣ����ڵ�һ���з�����0���Ͱ�������һ��λ�ð�һ�£�ʣ�µ����Դ�����
        // ���һ�в��ð�����Ϊû����һ�и������ˣ�����i���ȡ��3
        for(int i=0;i<4;++i)
            for(int j=0;j<5;++j)
                if(g[i][j]=='0')
                {
                    res++;
                    turn(i+1,j);
                }

        // ���һ�в�ȫΪ0�Ļ���˵�������ʽ���Ϸ�
        bool flag=true;
        for(int j=0;j<5;++j){
            if(g[4][j]=='0')
            {
                flag=false;
                break;
            }
        }

        // �������Ϸ��Ļ�����������С������
        if(flag)ans=min(ans,res);

        // �ָ����飬������һ��ö��
        memcpy(g,backup,sizeof g);
    }

    // 6�������޷�ʹ���еƱ����������"-1"
    if(ans>6)ans=-1;
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<5;++i)cin>>g[i];
        cout<<work()<<endl;
    }
    return 0;
}