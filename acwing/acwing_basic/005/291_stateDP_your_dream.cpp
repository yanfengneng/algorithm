#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 12, M = 1 << N;
// �ܷ�������ʵ���Ǻ��ŷŵ�С����ĺϷ�����������ǰ�ڷ�����ŵ�С����󣬿��������ŵ�С���齫����������ô�����ķ��������ǺϷ��ģ�
// f[i][j]��ʾ�Ѿ���i-1�аں��ˣ����Ҵӵ�i-1���쵽��i�е�״̬��j�ķ�����
LL f[N][M];
// �洢��k��j�����кϷ�״̬k����������ÿ�ζ�ȥѭ��һ��j k�ٽ����ж��˷�ʱ��
vector<int> state[M];
// �жϵ�ǰ��һ���Ƿ�����1x2��С������������ǰ��һ�������������ŵ�λ���Ƿ�Ϊż��
bool st[M];
int n,m;

int main()
{
    while(cin>>n>>m,n||m)
    {
        // ����Ԥ������st���飬��ʾÿ��״̬������0�Ƿ�Ϊż����
        for(int i=0;i<1<<n;++i)
        {
            // cnt������ʾ0�ĸ���
            int cnt=0;
            // ��ʾ�Ƿ�Ϸ�
            bool valid=true;
            // �������Ļ���ÿ�оͻ���n����
            for(int j=0;j<n;++j)
                if(i>>j&1)// i�ĵ�jλΪ1
                {
                    if(cnt&1)// ��������������0�Ļ������ʾ���Ϸ�
                    {
                        valid=false;
                        break;
                    }
                    // ͬʱ��cnt������գ���Ϊcntֻ����ͳ��������0������1�˾���Ҫ�������¼�����
                    cnt=0;
                }
                else cnt++;

            // �����һ��ҲΪ�����Ļ���ҲҪ��Ϊfalse
            if(cnt&1)valid=false;
            st[i]=valid;
        }

        // Ԥ��������ת�Ƶ�ÿ��״̬������k->j�ĺϷ�״̬k�������ڽ���״̬ת�Ƶ�ʱ�򣬾Ͳ���Ҫÿ�ζ�ȥѭ��һ��j��k�����ж���
        // ��i-2���쵽��i-1�е�״̬Ϊj����i-1���쵽��i�е�״̬Ϊk
        for(int j=0;j<1<<n;++j)
        {
            state[j].clear();
            /* 
            ��k�Ƶ�j�Ļ�����Ҫ����������
                1��j��k������ͬһ�У�����ᷢ����ײ����β��ײ��
                2�������������ŵ�λ�õĳ��ȱ���Ϊż��
            */  
            for(int k=0;k<1<<n;++k)
                // k ��ʾ��i-1�е�״̬������i-1�п����λ�õĳ��ȱ���Ϊż����j|k��ʾ��i-1�к͵�i����Ӧλ�ö���1��������ʵ���ǵ�i-1�б������ĳ�����
                if((j&k)==0&&st[j|k])
                    state[j].push_back(k);
        }

        memset(f,0,sizeof f);
        // ��ʾ��������һ�ַ���
        f[0][0]=1;
        // ��ʼ����״̬ת��
        for(int i=1;i<=m;++i)
            for(int j=0;j<1<<n;++j)
                // ���ڵ�i-1�е���i�е�С����İڷ��Ѿ��ǹ̶����ˣ���j�ǹ̶����ˣ������ڼ��ϻ��ֵ�ʱ��i-2�е���i-1�еķ����Ǳ仯�ģ���k�Ǳ仯�ģ��Ӽ�k�ķ����͵���j
                for(auto k:state[j])
                    f[i][j]+=f[i-1][k];
        
        // f[m][0]��ʾǰm-1���Ѿ��ں��ˣ��±��0��ʼ��Ҳ�������������Ѿ��ں��ˣ����Ҵӵ�m-1�����쵽��m�е�״̬Ϊ0����ʾû���κ�һ������������������ǡ����������̵����з�����
        cout<<f[m][0]<<endl;
    }
    return 0;
}