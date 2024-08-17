#include <iostream>
using namespace std;

class MyListForward
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){}
    };
    ListNode* head;
public:
    MyListForward():head(nullptr){}

    //1、获得链表中第index个节点的值
    int get(int index){
        int i=0;
        ListNode *p=head;
        while(p&&i<index){
            p=p->next;
            i++;
        }
        if(p)return p->val;
        else return -1;
    }

    //2、在链表头部插一个值为val的节点
    void addAtHead(int val){
        ListNode *p=new ListNode(val);
        p->next=head;
        head=p;//更换头节点
    }

    //3、在链表尾部添加一个值为val的节点
    void addAtTail(int val){
        ListNode *p=new ListNode(val);
        //链表为空，直接将新节点作为头节点
        if(head==nullptr){
            head=p;
            return;
        }
        ListNode *q=head;
        //遍历直到q的next节点为空
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }

    //4、在索引为index的节点之前添加值为val的节点
    void addAtIndex(int index,int val){
        ListNode *node=new ListNode(val);
        //1、index小于等于0，直接在头部插入节点
        if(index<=0)
        {//若index小于等于0，我们仅需要在头节点前面插入新节点就行了
        //注意这里不能使用指针p，因为p=node时，p所指向的地址发生了变化，head指向的地址没有变化，所以我们这里要使用指针head
            node->next=head;
            head=node;
            return;
        }
        int i=0;
        ListNode *p=head;
        //在索引为index的节点之前插入新节点，我们需要找到它的前驱节点，然后插入在它的前驱节点后面
        while(p&&i<index-1)
        {
            p=p->next;
            ++i;
        }
        //2、p为索引节点的前驱节点
        if(p)
        {
            node->next=p->next;
            p->next=node;
        }
    }

    //5、删除索引为index的节点
    void deleteAtIndex(int index){
        //1、index为0，我们直接删除head节点
        if(index==0&&head!=nullptr)
        {
            ListNode *del=head;
            head=head->next;
            delete del;
            return;
        }
        int i=0;
        ListNode* p=head;
        //删除索引为index的节点，我们需要找到它的前驱节点p，p->next为需要删除节点
        while(p&&i<index-1)
        {
            p=p->next;
            i++;
        }
        //2、index超过链表范围，删除失败
        if(!p)return;
        //3、index的位置合法，我们找到需要删除的p->next节点
        if(p->next)
        {
            ListNode *del=p->next;
            p->next=del->next;
            delete del;
        }
    }

    //6、链表长度
    int length(){
        int i=0;
        ListNode *p=head;
        while(p){
            i++;
            p=p->next;
        }
        return i;
    }

    //7、清空链表
    void clear(){
        ListNode *del=nullptr;
        while(head){
            del=head;
            head=head->next;
            delete del;
        }
    }
};

int main()
{
    MyListForward mlf;
    mlf.addAtIndex(0,10);
    mlf.addAtIndex(0,20);
    mlf.addAtIndex(1,30);
    for(int i=0;i<mlf.length();++i){
        cout<<mlf.get(i)<<" ";
    }
    cout<<endl;
    mlf.clear();
    cout<<mlf.length()<<endl;
    system("pause");
}