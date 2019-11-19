#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //�������ֱ���ų�
        if(s.empty()||words.empty())return {};
        
        //��Ž��������
        vector<int> result;
        
        //���������еĵ��ʵĴ�С���������Լ��ܳ���
        int one_word=words[0].size();
        int word_num=words.size();
        int all_len=one_word*word_num;
        
        //��������->���ʸ�����ӳ��
        unordered_map<string,int> m1;
        for(const auto& w:words)m1[w]++;
        
        for(int i=0;i<one_word;++i)
        {
            //left��rigth��ʾ���ڵ����ұ߽磬count����ͳ��ƥ��ĵ��ʸ���
            int left=i,right=i,count=0;
            
            unordered_map<string,int>m2;
            
            //��ʼ��������
            while(right+one_word<=s.size())
            {
                //��s����ȡһ�����ʿ�����w
                string w=s.substr(right,one_word);
                right+=one_word;//�����ұ߽�����һ�����ʵĳ���
                
                if(m1.count(w)==0){//�˵��ʲ���words�У���ʾƥ�䲻�ɹ�,Ȼ�����õ��ʸ��������ڱ߽硢�Լ�m2
                    count=0;
                    left=right;
                    m2.clear();
                }
                else{//�õ���ƥ��ɹ�����ӵ�m2��
                    m2[w]++;
                    count++;    
                    while(m2.count(w)>m1.count(w))//һ������ƥ���Σ���Ҫ��С����
                    {
                        string t_w=s.substr(left,one_word);
                        count--;
                        m2[t_w]--;
                        left+=one_word;
                    }
                    if(count==word_num)result.push_back(left);
                }
            }
        }
        return result;
    }
};

int main()
{
    string s= "wordgoodgoodgoodbestword";
    vector<string> words={"word","good","best","word"};
    vector<int> v=Solution().findSubstring(s,words);
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}