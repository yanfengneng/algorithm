#include <iostream>
#include <ctime>
using namespace std;

typedef int ElemType;

//������Ľڵ㶨��
typedef struct LNode{
    ElemType data;//�ڵ��������
    LNode *next;//nextָ��
}LNode,*LinkList;

//ͷ�巨����n�����ֵ�ĵ�����
bool createListHead(LinkList &L,int n){
    //����ͷ�ڵ�
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

//β�巨����n�����ֵ�ĵ�����
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

//���������е�i��Ԫ��
int getElem(LinkList L,int i){
    LNode *p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    //j>i��ʾi<1��i���ڱ�+1
    if(!p||j>i)return -1;
    return p->data;
}

//�ڵ�i��λ��֮ǰ����ֵΪe���½ڵ�
bool insertList(LinkList &L,int i,ElemType e){
    int j=1;
    LNode *p=L;
    //�ҵ���i������ǰ���ڵ�j
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

//ɾ����i���ڵ�
bool deleteList(LinkList &L,int i,ElemType &e){
    int j=1;
    LNode *p=L;
    //�ҵ���i���ڵ��ǰ���ڵ�p
    while(p->next&&j<i){
        p=p->next;
        j++;
    }
    //��i��Ԫ�ز����ڣ�ǰ���ڵ�p�����ڻ���iΪ0
    if(!p->next||j>i)return false;
    LNode *del=p->next;
    p->next=del->next;
    e=del->data;
    free(del);
    return true;
}

//�������
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

//��ӡ����
void printList(const LinkList& L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//������
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