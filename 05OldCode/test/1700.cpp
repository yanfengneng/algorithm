#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& stu, vector<int>& san) {
    queue<int> q;
    for(auto s:stu)q.push(s);
    stack<int> s;
    for(int i=san.size()-1;i>=0;i--)s.push(san[i]);
        
    while(q.size()&&s.size())
    {
        int n=q.size(),cnt=0;
        while(q.front()!=s.top())
        {
            cnt++;
            if(cnt==n)return n;
            int s=q.front();q.pop();
            q.push(s);
        }
        if(q.front()==s.top())q.pop(),s.pop();
    }
    return 0;
}

int main()
{
    vector<int> x={1,1,1,0,0,1},y={1,0,0,0,1,1};
    cout<<countStudents(x,y)<<endl;
    return 0;
}