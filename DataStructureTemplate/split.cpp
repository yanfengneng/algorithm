#include <bits/stdc++.h>
using namespace std;

// �ṩ�����汾��c++�ָ��ַ���
// �汾1������istringstream+getline�����ַ���
vector<string> split_1(string str)
{
    istringstream txt(str);
    vector<string> words;
    string word;
    // ����ԭ�ͣ�istream& getline ( istream &is , string &str , char delim );
    // ���ݵ����������ַ����л��ּ���
    while(getline(txt,word,' ')){
        // move(a)��a��ֵ����
        words.push_back(move(word));
    }
    return words;
}

// �汾2����ȫ�Լ���д��split
vector<string> split_2(string str,char delim)
{
    vector<string> words;
    string word;
    for(char ch:str){
        if(ch==delim){
            words.push_back(move(word));
            // move֮�������������ɺ�ϰ��
            word.clear();
        }
        else{
            word+=ch;
        }
    }
    // ���һ������ҲҪ��ӽ���
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
    return 0;
}