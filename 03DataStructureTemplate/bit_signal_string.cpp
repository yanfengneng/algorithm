#include <iostream>
using namespace std;

// a~z 26����ĸʹ��26λ�����ƴ洢��26���ַ�ֻ�洢һ��
int convert(string str){
    int mask=0;
    for(char ch:str){
        // 1<<n=2^n ��ʾ1����nλ
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