#include <iostream>
#include <ctime>
using namespace std;

typedef int ElemType;

//单链表的节点定义
typedef struct LNode{
    ElemType data;//节点的数据域
    LNode *next;//next指针
}LNode,*LinkList;

//头插法插入n个随机值的单链表
bool createListHead(LinkList &L,int n){
    //建立头节点
    L=(LNode*)malloc(sizeof(LNode));
    if(!L)return false;
    L->next=nullptr;
    LinkList p;
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;++i){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=rand()%100+1;
        p->next=L->next;
        L->next=p;
    }
    return true;
}

//尾插法插入n个随机值的单链表
bool createListTail(LinkList &L,int n){
    L=(LNode*)malloc(sizeof(LNode));
    if(!L)return false;
    LNode *tail=L,*cur=nullptr;
    srand((unsigned int)time(NULL));
    for(int i=0;i<n;++i){
        cur=(LNode*)malloc(sizeof(LNode));
        cur->data=rand()%100+1;
        tail->next=cur;
        tail=cur;
    }
    tail->next=nullptr;
    return true;
}

//返回链表中第i个元素
int getElem(LinkList L,int i){
    LNode *p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    //j>i表示i<1或i等于表长+1
    if(!p||j>i)return -1;
    return p->data;
}

//在第i个位置之前插入值为e的新节点
bool insertList(LinkList &L,int i,ElemType e){
    int j=1;
    LNode *p=L;
    //找到第i个结点的前驱节点j
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i)return false;
    LNode *s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//删除第i个节点
bool deleteList(LinkList &L,int i,ElemType &e){
    int j=1;
    LNode *p=L;
    //找到第i个节点的前驱节点p
    while(p->next&&j<i){
        p=p->next;
        j++;
    }
    //第i个元素不存在，前驱节点p不存在或者i为0
    if(!p->next||j>i)return false;
    LNode *del=p->next;
    p->next=del->next;
    e=del->data;
    free(del);
    return true;
}

//清空链表
bool clearList(LinkList &L){
    LinkList p=L->next,del;
    while(p){
        del=p;
        p=p->next;
        free(del);
    }
    L->next=nullptr;
    return true;
}

//打印链表
void printList(const LinkList& L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//链表长度
int length(const LinkList& L){
    int i=0;
    LNode *p=L->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

int main()
{
    LinkList L1,L2;
    createListHead(L1,10);
    createListTail(L2,10);
    printList(L1);
    printList(L2);
    int size=length(L1);
    for(int i=1;i<=size;++i){
        cout<<getElem(L1,i)<<" ";
    }
    cout<<endl;
    insertList(L1,1,999);
    printList(L1);
    ElemType e;
    deleteList(L1,10,e);
    cout<<e<<endl;
    printList(L1);
    clearList(L1);
    clearList(L2);
    printList(L1);
}