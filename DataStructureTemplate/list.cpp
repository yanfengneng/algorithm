#include <iostream>
using namespace std;

class MyList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next,*prev;
        ListNode(int x):val(x),next(nullptr),prev(nullptr){}
    };
private:
    //头节点尾节点都为空，表示为空链表
    ListNode *head,*tail;
    int size=0;
public:
    MyList():size(0),head(nullptr),tail(nullptr){}

    //1、获得索引为index的节点值
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

    //2、在头部插入值为val的新节点
    void addAtHead(int val){
        if(head!=nullptr){
            ListNode *node=new ListNode(val);
            node->next=head;
            head->prev=node;
            head=node;
        }
        else{
            head=new ListNode(val);
            tail=head;
        }
        ++size;
    }

    //3、在尾部插入值为val的新节点
    void addAtTail(int val){
        if(tail!=nullptr){
            ListNode *node=new ListNode(val);
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        else{//尾节点为空，那么头节点也为空，然后首尾节点都为新节点
            tail=new ListNode(val);
            head=tail;
        }
        ++size;
    }

    //4、在index之前添加值为val的新节点
    void addAtIndex(int index,int val){
        //首先排除三种特殊情况的index，然后剩下来的index肯定在链表内
        if(index<=0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index>size)return;
        ListNode *p=nullptr,*cur=head;
        int i=0;
        while(cur&&i<index){
            p=cur;
            cur=cur->next;
            i++;
        }
        ListNode *node=new ListNode(val);
        //由于前面已经将特殊情况的index排除了，现在的p和cur都有效，都在链表内
        p->next=node;
        node->prev=p;
        node->next=cur;
        cur->prev=node;
        size++;
    }

    //5、删除索引为index的节点
    void deleteAtIndex(int index){
        //链表为空时，不能删除
        if(!head)return;
        if(index==0)
        {
            ListNode *del=head;
            head=head->next;
            if(head){//链表有2个以上节点
                head->prev=nullptr;
            }
            else{//链表只有一个节点，将尾部制空
                tail=nullptr;
            }
            delete del;
            size--;
            return;
        }
        //index为最后为尾节点，我们需要删除尾节点
        if(index==size-1){
            ListNode *del=tail;
            tail=tail->prev;
            //注意这里不用处理tail为空，因为tail为空的话，那么链表只有单个节点
            //然而单个节点只能删除0号节点，只有index为0时才能删除，前面已经处理过了index为0的情况了，所以这里不在处理
            if(tail){
                tail->next=nullptr;
            }
            delete del;
            size--;
            return;
        }
        int i=0;
        ListNode *p=nullptr,*cur=head;
        while(cur){
            if(i==index){
                ListNode *del=cur;
                p->next=cur->next;
                if(cur->next){
                    cur->next->prev=p;
                }
                delete del;
                size--;
                return;
            }
            p=cur;
            cur=cur->next;
            ++i;
        }
    }

    //6、获得链表的长度
    int length(){
        return size;
    }

    //7、清空链表
    void clear(){
        for(int i=size-1;i>=0;--i){
            deleteAtIndex(i);
        }
    }
};

int main()
{
    MyList ml;
    ml.addAtHead(1);
    ml.addAtTail(3);
    ml.addAtHead(4);
    ml.addAtHead(5);
    ml.addAtIndex(1,2);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.deleteAtIndex(1);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.clear();
    cout<<ml.length()<<endl;
    system("pause");
}