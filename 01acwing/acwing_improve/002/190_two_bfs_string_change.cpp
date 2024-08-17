#include <bits/stdc++.h>
using namespace std;

const int N = 6;
int n;
string A,B;
// ת������ a[i] -> b[i]
string a[N],b[N];

int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[])
{
    // ��ǰ��ͷ�϶���û�б�b���ʹ��ģ������Ҫ������չһ��
    string t=q.front();q.pop();
    // ö�����е���չ��ʽ����ö����չ����㣬��ö���¹���
    for(int i=0;i<t.size();++i)
        for(int j=0;j<n;++j)
            // t[i...i+size]=a[j] ����������ʹ��ת�����򣬽� a[j] ת��Ϊ b[j]
            if(t.substr(i,a[j].size())==a[j])
            {
                string state=t.substr(0,i)+b[j]+t.substr(i+a[j].size());
                // ����չ����״̬�ڶ���b�У����ʱ�����������ˣ�����Ϊ A->t->state->B
                if(db.count(state))return da[t]+1+db[state];
                // ����ÿ��״ֻ̬�ᱻ����һ�Σ���˷��ʵ�״̬�Ͳ���Ҫ�ٴη�����
                if(da.count(state))continue;
                // ������㵽state�ľ��룬�Լ��ڶ����м������״̬
                da[state]=da[t]+1,q.push(state);
            }
    // �� A �޷���չ�� B��ֱ�ӷ��� 11
    return 11;
}

int bfs()
{
    if(A==B)return 0;
    // qa����㿪ʼ�ѣ�qb���յ㿪ʼ�ѡ���Ҫ������������Ķ��У������洢״̬
    queue<string> qa,qb;
    // �ֱ�洢ÿ��״̬����ʼλ�õľ��룬da �洢��չ���ĵ㵽���ľ��룬db �洢��չ���ĵ㵽�յ�ľ���
    unordered_map<string,int> da,db;
    // �洢��ʼλ�úͳ�ʼ����ʼ����
    qa.push(A),da[A]=0;
    qb.push(B),db[B]=0;

    // ֻҪ�������ж���Ϊ��ʱ�����ܼ�����չ��������һ��Ϊ�գ����߶�Ϊ�գ�˵��A B��һ������ͨ�ģ������ڽ���������ֻҪ�м�����ͨ�ģ���һ�����Ա��ȥ��
    while(qa.size()&&qb.size())
    {
        int t;
        // ����ÿ��ѡ���״̬���ٵĶ��п�ʼ������չ������������ʱ�临�Ӷȡ�
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