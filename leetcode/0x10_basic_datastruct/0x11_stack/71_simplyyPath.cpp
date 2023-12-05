#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路：先根据'/'划分path，然后用栈按照题目意思模拟即可
    string simplifyPath(string path) {
        vector<string> names=split(path);
        vector<string> stack;
        for(const string &name:names){
            // 遇到".."就返回上一次目录，即弹栈
            if(name==".."){
                // 这两个 if 一定要分开写，不然name==".."和stack为空时就会添加".."了
                if(stack.size())stack.pop_back();
            }
            // 遇到空字符串或"."，不需要切换目录，即什么也不做；遇到目录名，添加到栈中即可
            else if(name.size()&&name!="."){
                stack.push_back(move(name));
            }
        }
        // 栈为空，表示回到根目录了，直接返回"/"即可
        if(stack.empty())return "/";
        string res="";
        // 栈底存放的是仅次于根目录的目录名，栈顶存放叶子节点文件名，用"/"拼接起来即为最终结果
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