#include <iostream>
using namespace std;

typedef int SElemType;
#define MaxSize 200

//À≥–Ú’ª
typedef struct SqStack
{
    SElemType data[MaxSize];
    int top;    //”√”⁄’ª∂•÷∏’Î   
}SqStack;

void initStack(SqStack& S){
    S.top=-1;
}

bool isEmpty(const SqStack& s){
    if(s.top==-1)return true;
    return false;
}

int length(const SqStack& S){
    return S.top+1;
}

bool push(SqStack& S,SElemType e){
    if(S.top==MaxSize-1)return false;
    S.data[++S.top]=e;
    return true;
}

bool pop(SqStack& S,SElemType &e){
    if(S.top==-1)return false;
    e=S.data[S.top--];
    return true;
}

int main()
{
    SqStack S;
    initStack(S);
    for(int i=0;i<10;++i){
        push(S,i);
    }
    SElemType e;
    int size=length(S);
    for(int i=0;i<size;++i){
        pop(S,e);
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<isEmpty(S)<<endl;
}