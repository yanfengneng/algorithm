#include <bits/stdc++.h>
using namespace std;

// c++ 实现 replace
string replace(string source, string a, string b)
{
    string::size_type pos = 0;
    // 在字符串 source 中从下标 pos 开始寻找子串 a
    while((pos=source.find(a,pos))!=string::npos)   //替换所有指定子串
    {
        source.replace(pos, a.length(), b);
        pos+=b.length();
    }
    return source;
}

// 提供两个版本的c++分割字符串
// 版本1：利用istringstream+getline划分字符串
vector<string> split_1(string str)
{
    istringstream txt(str);
    vector<string> words;
    string word;
    // 函数原型：istream& getline ( istream &is , string &str , char delim );
    // 根据第三个参数字符进行划分即可
    while(getline(txt,word,' ')){
        // move(a)将a的值移走
        words.push_back(move(word));
    }
    return words;
}

// 版本2：完全自己手写的split
vector<string> split_2(string str,char delim)
{
    vector<string> words;
    string word;
    for(char ch:str){
        if(ch==delim){
            words.push_back(move(word));
            // move之后进行清除，养成好习惯
            word.clear();
        }
        else{
            word+=ch;
        }
    }
    // 最后一个单词也要添加进来
    words.push_back(move(word));
    word.clear();
    return words;
}

int main()
{
    string str="shang an shang an";
    vector<string> a=split_1(str),b=split_2(str,' ');
    for(auto c:a)cout<<c<<"!";
    cout<<endl;
    for(auto c:b)cout<<c<<"!";
    cout<<endl;

    string s="1.1.1.1";
    cout<<replace(s,".","[.]")<<endl;
    return 0;
}