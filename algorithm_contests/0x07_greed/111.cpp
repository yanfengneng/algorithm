#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 5e5+10;
using PII = pair<int,int>;
// �洢<���䣬��ţ���>
pair<PII,int> cows[N];
int id[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>cows[i].x.x>>cows[i].x.y;
        cows[i].y=i;
    }

    // ����˵���С�����������
    sort(cows,cows+n,[](const auto& a,const auto& b){
        return a.x.x<b.x.x;
    });

    // ���д�ŵ�Ԫ��Ϊ<��ǰ�����������Ҷ˵����Сֵ��������>
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    // ����˵��С����ö�ټ���
    for(int i=0;i<n;++i)
    {
        // ��Ϊ�ջ��߶����Ҷ˵����Сֵ���ڵ��ڵ�ǰ�������˵㣬��ʾ�����ཻ����Ҫ�¿�һ�����飬�ٰѵ�ǰ����Ž�ȥ
        if(heap.empty()||heap.top().x>=cows[i].x.x)
        {
            // ��������Ҷ˵㣬������
            PII stall={cows[i].x.y,heap.size()};
            // ��ţi����ŵ�����stall.y��
            id[cows[i].y]=stall.y;
            // ����µķ���
            heap.push(stall);
        }
        //  �����ʾ��ǰ���������ӵ��Ҷ˵���Сֵ�ķ����У����Ҷ˵���Сֵ���и���Ϊ��ǰ������Ҷ˵�
        else
        {
            auto stall=heap.top();heap.pop();
            // ���ºϲ�������µ��Ҷ˵�
            stall.x=cows[i].x.y;
            // ��ţi������ڷ���stall.y��
            id[cows[i].y]=stall.y;
            // �������Ҷ˵�֮��ķ��飬������ӵ�����
            heap.push(stall);
        }
    }

    cout<<heap.size()<<endl;
    for(int i=0;i<n;++i)cout<<id[i]+1<<endl;
    return 0;
}