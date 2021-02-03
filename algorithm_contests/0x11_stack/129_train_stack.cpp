#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n;
vector<int> a;

// �ж�ջ�Ƿ��ǺϷ�����
bool check()
{
    // ��q���洢��ջ���У�����s��ģ�������е�Ԫ�صĳ�ջ����ջ
    queue<int> q;
    stack<int> s;
    for(auto x:a)q.push(x);
    // ���ڶ��еĶ�ͷԪ��Ϊ���ȳ�ջ��Ԫ�أ�����ֻҪջ��ջ��Ԫ�غͶ��еĶ�ͷԪ����ȣ��ͱ�ʾ��Ԫ��������ջ��ͬʱ����ͷ��ջ��pop����
    // i��1��ʼ������ʾ��������ջ����
    for(int i=1;i<=n;++i)
    {
        s.push(i);
        while(s.size()&&s.top()==q.front())s.pop(),q.pop();
    }
    if(s.empty())return true;
    else return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)a.push_back(i);
    int cnt=0;
    do
    {
        if(check())
        {
            for(auto x:a)printf("%d",x);
            puts("");
            cnt++;
        }
        if(cnt==20)break;
    }while(next_permutation(a.begin(),a.end()));

    return 0;
}