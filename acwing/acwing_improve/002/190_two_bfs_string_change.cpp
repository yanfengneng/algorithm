#include <bits/stdc++.h>
using namespace std;

const int N = 6;
int n;
string A,B;
// 转换规则 a[i] -> b[i]
string a[N],b[N];

int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[])
{
    // 当前队头肯定是没有被b访问过的，因此需要进行扩展一层
    string t=q.front();q.pop();
    // 枚举所有的扩展方式：先枚举扩展的起点，再枚举下规则
    for(int i=0;i<t.size();++i)
        for(int j=0;j<n;++j)
            // t[i...i+size]=a[j] 表明这块可以使用转换规则，将 a[j] 转换为 b[j]
            if(t.substr(i,a[j].size())==a[j])
            {
                string state=t.substr(0,i)+b[j]+t.substr(i+a[j].size());
                // 若扩展到的状态在队列b中，则此时两队列相遇了，距离为 A->t->state->B
                if(db.count(state))return da[t]+1+db[state];
                // 由于每个状态只会被访问一次，因此访问的状态就不需要再次访问了
                if(da.count(state))continue;
                // 更新起点到state的距离，以及在队列中加入这个状态
                da[state]=da[t]+1,q.push(state);
            }
    // 从 A 无法扩展到 B，直接返回 11
    return 11;
}

int bfs()
{
    if(A==B)return 0;
    // qa从起点开始搜，qb从终点开始搜。需要建立两个方向的队列，用来存储状态
    queue<string> qa,qb;
    // 分别存储每个状态到起始位置的距离，da 存储扩展到的点到起点的距离，db 存储扩展到的点到终点的距离
    unordered_map<string,int> da,db;
    // 存储起始位置和初始化起始距离
    qa.push(A),da[A]=0;
    qb.push(B),db[B]=0;

    // 只要两个队列都不为空时，才能继续扩展。若其中一个为空，或者都为空，说明A B是一定不连通的，不存在交集；否则只要中间是连通的，就一定可以变过去。
    while(qa.size()&&qb.size())
    {
        int t;
        // 我们每次选择从状态数少的队列开始进行扩展，这样来降低时间复杂度。
        if(qa.size()<=qb.size())t=extend(qa,da,db,a,b);
        else t=extend(qb,db,da,b,a);
        if(t<=10)return t;
    }
    return 11;
}

int main()
{
    cin>>A>>B;
    while(cin>>a[n]>>b[n])n++;
    int step=bfs();
    if(step>10)cout<<"NO ANSWER!"<<endl;
    else cout<<step<<endl;
    return 0;
}