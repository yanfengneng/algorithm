#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n;
vector<int> a;

// 判断栈是否是合法序列
bool check()
{
    // 用q来存储出栈序列，而用s来模拟序列中的元素的出栈和入栈
    queue<int> q;
    stack<int> s;
    for(auto x:a)q.push(x);
    // 由于队列的队头元素为最先出栈的元素，所以只要栈的栈顶元素和队列的队头元素相等，就表示该元素正常出栈，同时将队头和栈顶pop即可
    // i从1开始遍历表示正常的入栈次序
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