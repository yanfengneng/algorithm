#include <iostream>
using namespace std;

typedef int SElemType;

//��ջ�ڵ�
//��ջ��nextָ���Ǵ�ջ��ָ��ջ�׵ģ�����������push��ʱ��ע��nextָ���ָ��
typedef struct SNode
{
    SElemType data;
    SNode *next;
}SNode,*LinkStackPtr;

typedef struct LinkStack
{
    int count;//ջ��Ԫ�ظ���
    LinkStackPtr top;//ջ��ָ��
}LinkStack;

void initStack(LinkStack& S){
    S.count=0;
    S.top=nullptr;
}

bool push(LinkStack& S,SElemType e){
    LinkStackPtr node=(LinkStackPtr)malloc(sizeof(SNode));
    if(!node)return false;
    node->data=e;
    node->next=S.top;
    S.top=node;
    S.count++;
    return true;
}

bool pop(LinkStack& S,SElemType& e){
    if(S.count==0)return false;
    e=S.top->data;
    LinkStackPtr del=S.top;
    S.top=S.top->next;
    free(del);
    S.count--;
    return true;
}

int main()
{
    LinkStack S;
    initStack(S);
    for(int i=10;i>0;--i){
        push(S,i);
    }
    SElemType e;
    cout<<S.count<<endl;
    int size=S.count;
    for(int i=0;i<size;++i){
        pop(S,e);
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<S.count<<endl;
}