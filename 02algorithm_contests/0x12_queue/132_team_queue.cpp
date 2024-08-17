#include <iostream>
#include <queue>
using namespace std;

// 每个小组最多1k人，总共1k*1k个人，所以最多有1k组
const int N=1010,M=1e6;

// teamid[x]=i表示编号x的组号为i
int teamid[M];

int main()
{
    int t,C=1;
    // 在输入数字t时，同时判断t是否为0，为0就退出循环
    while(scanf("%d",&t),t)
    {
        printf("Scenario #%d\n",C++);
        // 处理0~t-1组，每组人数以及编号输入
        for(int i=0;i<t;++i)
        {
            int cnt;
            scanf("%d",&cnt);
            while(cnt--)
            {
                int x;
                scanf("%d",&x);
                // 编号x的组号为i
                teamid[x]=i;
            }
        }
        // team存储组间顺序；preson存储组内顺序
        queue<int> team;
        queue<int> person[N];

        string command;
        while(cin>>command,command!="STOP")
        {
            if(command=="ENQUEUE")// 入队
            {
                int x;
                cin>>x;
                // 取出编号x对应的组号tid
                int tid=teamid[x];
                // 若这组为空，则将这组的组号插入组间顺序队列
                if(person[tid].empty())team.push(tid);
                // 在tid这组插入编号x
                person[tid].push(x);
            }
            else    // 出队
            {
                // 取出组间顺序中最前面的组号
                int tid=team.front();
                // 引用tid这组的队列
                auto &q=person[tid];
                cout<<q.front()<<endl;
                q.pop();
                // tid这组队列清空了，则在team的开头删除tid
                if(q.empty())team.pop();
            }
            
        }
        cout<<endl;
    }
    return 0;
}