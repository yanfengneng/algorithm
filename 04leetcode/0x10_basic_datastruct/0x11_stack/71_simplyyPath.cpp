#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ˼·���ȸ���'/'����path��Ȼ����ջ������Ŀ��˼ģ�⼴��
    string simplifyPath(string path) {
        vector<string> names=split(path);
        vector<string> stack;
        for(const string &name:names){
            // ����".."�ͷ�����һ��Ŀ¼������ջ
            if(name==".."){
                // ������ if һ��Ҫ�ֿ�д����Ȼname==".."��stackΪ��ʱ�ͻ����".."��
                if(stack.size())stack.pop_back();
            }
            // �������ַ�����"."������Ҫ�л�Ŀ¼����ʲôҲ����������Ŀ¼������ӵ�ջ�м���
            else if(name.size()&&name!="."){
                stack.push_back(move(name));
            }
        }
        // ջΪ�գ���ʾ�ص���Ŀ¼�ˣ�ֱ�ӷ���"/"����
        if(stack.empty())return "/";
        string res="";
        // ջ�״�ŵ��ǽ����ڸ�Ŀ¼��Ŀ¼����ջ�����Ҷ�ӽڵ��ļ�������"/"ƴ��������Ϊ���ս��
        while(stack.size()){
            res="/"+stack.back()+res;
            stack.pop_back();
        }
        return res;
    }

    vector<string> split(const string& path){
        istringstream txt(path);
        vector<string> words;
        string word;
        while(getline(txt,word,'/')){
            words.push_back(move(word));
        }
        return words;
    }
};

int main()
{
    cout<<Solution().simplifyPath("/../")<<endl;
    return 0;
}