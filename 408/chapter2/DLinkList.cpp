#include <iostream>
#include <ctime>
using namespace std;

typedef int ElemType ;
typedef struct DNode{
    ElemType data;
    DNode *prev,*next;
}DNode,*DLinkList;

bool insertDLinkList(DLinkList& L,int i,ElemType e){
    int j=1;
    DNode *p=L;
    //找到第i个结点的前驱节点j
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i)return false;
    DNode *s=(DNode*)malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    p->next->prev=s;
    s->prev=p;
    p->next=s;
    return true;
}

bool deleteDLinkList(DLinkList& L,int i,ElemType& e){
    int j=1;
    DNode *p=L;
    //找到第i个节点的前驱节点p
    while(p->next&&j<i){
        p=p->next;
        j++;
    }
    //第i个元素不存在，前驱节点p不存在或者i为0
    if(!p->next||j>i)return false;
    DNode *del=p->next;
    p->next=del->next;
    del->next->prev=p;
    e=del->data;
    free(del);
    return true;
}

void printDlinkList(const DLinkList& L){
    DNode *p=L->next;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void createDLinkList(DLinkList &L,int n){
    L=(DNode*)malloc(sizeof(DNode));
    L->next=nullptr,L->prev=nullptr;
    DNode *tail=L,*p;
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;++i){
        p=(DNode*)malloc(sizeof(DNode));
        p->data=rand()%100+1;
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
    tail->next=nullptr;
}
int main()
{
    DLinkList L;
    createDLinkList(L,1);
    for(int i=1;i<=10;++i){
        insertDLinkList(L,i,i*2);
    }
    printDlinkList(L);
    ElemType e;
    for(int i=1;i<=5;++i){
        deleteDLinkList(L,i,e);
        cout<<e<<endl;
    }
    printDlinkList(L);
}