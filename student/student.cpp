#include <bits/stdc++.h>
using namespace std;

typedef struct student
{
    char name[20];
    char sex[10];
    int id;
}Student;

struct Node
{
    Node *next;
    Student stu;
};

// 定义文件指针和头指针
FILE *fp;
Node* head;

// 创造头节点
void createHead()
{
    head=new Node();
    head->next=nullptr;
}

// 增
void add()
{
    cout<<"请依次输入学生的姓名，性别，学号："<<endl;
    Node *node=new Node();
    if(node==nullptr){
        cout<<"内存分配失败，录入失败\n";
        return;
    }
    cin>>node->stu.name>>node->stu.sex>>node->stu.id;
    node->next=nullptr;
    if(head->next==nullptr){
        head->next=node;
    }
    else{   // 头插法
        Node *tmp=head->next;
        node->next=tmp;
        head->next=node;
    }
    cout<<"录入成功！\n";
    system("pause");
    system("cls");
}

// 删
void del()
{
    cout<<"请输入需要删除学生的ID："<<endl;
    int id;
    cin>>id;
    Node *p=head;
    while(p&&p->next)
    {
        if(p->next->stu.id==id){
            Node *tmp=p->next;
            if(tmp->next)p->next=tmp->next;
            else p->next=nullptr;
            delete(tmp);
            cout<<"删除成功！"<<endl;
            return;
        }
        else{
            p=p->next;
        }
    }
    cout<<"不存在该ID的学生！"<<endl;
}

// 查
void find()
{
    cout<<"请输入需要查询学生的ID："<<endl;
    int id;
    cin>>id;
    Node *p=head;
    while(p)
    {
        if(p->stu.id==id){
            cout<<"查询成功！"<<endl;
            cout<<p->stu.name<<"\t"<<p->stu.sex<<"\t"<<p->stu.id<<endl;
            return;
        }
        else p=p->next;
    }
    cout<<"不存在该ID的学生！"<<endl;
}

// 改
void update()
{
    cout<<"请输入需要更改的学生ID："<<endl;
    int id;
    cin>>id;
    Node *p=head;
    while(p)
    {
        if(p->stu.id==id){
            cout<<"请输入更改后的学生姓名，性别，学号："<<endl;
            scanf("%s %s %d",p->stu.name,p->stu.sex,&p->stu.id);
            cout<<"更改成功！"<<endl;
            return;
        }
        else p=p->next;
    }
    cout<<"不存在该ID的学生！"<<endl;
}

// 将链表信息加载到文件中
void save()
{
    Node *p=head;
    if((fp=fopen("student.txt","w"))==nullptr)
    {
        cout<<"文件保存失败！不能获得文件句柄！"<<endl;
        system("pause");
        return;
    }
    while (p != NULL)
	{
        // 将链表信息保存在文件中
		fprintf(fp, "%s %s %d\n", p->stu.name, p->stu.sex, p->stu.id);
		p = p->next;
	}
    fclose(fp);
    cout<<"保存成功！"<<endl;
    system("pause");
    system("cls");
}

// 将文件信息加载在链表中
void LoadDate()
{
    if ((fp = fopen("student.txt", "a+"))==nullptr)
	{
		printf("\n文件打开失败！不能获得文件句柄！\n");
		system("pause");
        system("cls");
		return;
	}
    Node *p=new Node();
    p->next=nullptr;
    while(fscanf(fp,"%s %s %d",p->stu.name,p->stu.sex,&p->stu.id)!=EOF)
    {
        if(head->next==nullptr){
            head->next=p;
        }
        else{   // 头插法
            Node *tmp=head->next;
            p->next=tmp;
            head->next=p;
        }
    }
    fclose(fp);
    cout<<"加载成功！"<<endl;
    system("pause");
    system("cls");
}

int main()
{
    createHead();
    while(1){
        add();
    }
}