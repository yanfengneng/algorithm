#include <bits/stdc++.h>
using namespace std;

// ������¼����i�Ƿ���ʹ�
bool visited[210];

int findCircleNum(vector<vector<int>> &isConnected)
{
    memset(visited, 0, sizeof visited);
    int n = isConnected.size();
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        // ������iû�б����ʹ����򽫶���i�������ڽڵ���з��ʣ�ʹ��bfs
        queue<int> q;
        if (!visited[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                visited[t] = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (isConnected[t][j] && !visited[j])
                    {
                        q.push(j);
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int res=findCircleNum(isConnected);
    return 0;
}