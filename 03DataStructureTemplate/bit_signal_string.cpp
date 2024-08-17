#include <iostream>
using namespace std;

// a~z 26个字母使用26位二进制存储，26个字符只存储一次
int convert(string str){
    int mask=0;
    for(char ch:str){
        // 1<<n=2^n 表示1左移n位
        mask|=1<<(ch-'a');
    }
    return mask;
}

int main()
{
    string str="";
    for(char ch='a';ch<='z';++ch){
        str+=ch;
        cout<<convert(str)<<endl;
    }
    return 0;
}