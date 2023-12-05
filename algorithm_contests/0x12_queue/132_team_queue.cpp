#include <iostream>
#include <queue>
using namespace std;

// ÿ��С�����1k�ˣ��ܹ�1k*1k���ˣ����������1k��
const int N=1010,M=1e6;

// teamid[x]=i��ʾ���x�����Ϊi
int teamid[M];

int main()
{
    int t,C=1;
    // ����������tʱ��ͬʱ�ж�t�Ƿ�Ϊ0��Ϊ0���˳�ѭ��
    while(scanf("%d",&t),t)
    {
        printf("Scenario #%d\n",C++);
        // ����0~t-1�飬ÿ�������Լ��������
        for(int i=0;i<t;++i)
        {
            int cnt;
            scanf("%d",&cnt);
            while(cnt--)
            {
                int x;
                scanf("%d",&x);
                // ���x�����Ϊi
                teamid[x]=i;
            }
        }
        // team�洢���˳��preson�洢����˳��
        queue<int> team;
        queue<int> person[N];

        string command;
        while(cin>>command,command!="STOP")
        {
            if(command=="ENQUEUE")// ���
            {
                int x;
                cin>>x;
                // ȡ�����x��Ӧ�����tid
                int tid=teamid[x];
                // ������Ϊ�գ����������Ų������˳�����
                if(person[tid].empty())team.push(tid);
                // ��tid���������x
                person[tid].push(x);
            }
            else    // ����
            {
                // ȡ�����˳������ǰ������
                int tid=team.front();
                // ����tid����Ķ���
                auto &q=person[tid];
                cout<<q.front()<<endl;
                q.pop();
                // tid�����������ˣ�����team�Ŀ�ͷɾ��tid
                if(q.empty())team.pop();
            }
            
        }
        cout<<endl;
    }
    return 0;
}