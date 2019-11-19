#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
        //1:����hashmap��˳��ȥ���ظ�Ԫ��
        unordered_map<string,int> mp;
        for(const auto& b:bank)mp[b]=0;
        
        //2:�ų����������end���ڻ������
        if(mp.count(end)==0)return -1;
        
        //3:bfs�ĳ�ʼ������
        queue<string> q1({start}),q2({end});//ǰ����У��������
        int step=0;
        const char table[4]={'A','C','G','T'};//
        //��1��ʾǰ�������ǰ�����������2��ʾ��������ɺ���ǰ������ÿ������ѡ�ý�С�Ķ��н��б���
        for(mp[start]|=1,mp[end]|=2;q1.size()&&q2.size();++step)//ÿ������һ�Σ�����+1
        {
            bool first=q1.size()<q2.size();
            queue<string> &q=first?q1:q2;//ѡ���С�Ķ��н��б�����Լʱ��
            int flag=first?1:2;//�˴α����ķ�ʽ
            
            for(int n=q.size();n--;q.pop()){
                string& temp=q.front();
                if(mp[temp]==3)return step;//����������ͷ�����ز���
                for(int i=0;i<temp.size();++i){
                    for(int j=0;j<4;++j){
                        string s=temp;
                        if(s[i]==table[j])continue;//�ظ��ַ�������ѭ����Ѱ����һ���ַ�
                        s[i]=table[j];
                        if(mp.count(s)==0||mp[s]&flag)continue;//�õ��ʲ���map�л�õ����Ѿ����������ˣ�����ѭ����Ѱ����һ������
                        mp[s]|=flag;//��Ǹõ����Ѿ�����������
                        q.push(s);
                    }
                }
            }
        }
        return -1;
}

int main()
{
    vector<string> bank{"EACCGGTT"};
    string start="AACCGGTT",end="EACCGGTT";
    cout<<minMutation(start,end,bank)<<endl;
    return 0;
}