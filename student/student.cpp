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

// �����ļ�ָ���ͷָ��
FILE *fp;
Node* head;

// ����ͷ�ڵ�
void createHead()
{
    head=new Node();
    head->next=nullptr;
}

// ��
void add()
{
    cout<<"����������ѧ�����������Ա�ѧ�ţ�"<<endl;
    Node *node=new Node();
    if(node==nullptr){
        cout<<"�ڴ����ʧ�ܣ�¼��ʧ��\n";
        return;
    }
    cin>>node->stu.name>>node->stu.sex>>node->stu.id;
    node->next=nullptr;
    if(head->next==nullptr){
        head->next=node;
    }
    else{   // ͷ�巨
        Node *tmp=head->next;
        node->next=tmp;
        head->next=node;
    }
    cout<<"¼��ɹ���\n";
    system("pause");
    system("cls");
}

// ɾ
void del()
{
    cout<<"��������Ҫɾ��ѧ����ID��"<<endl;
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
            cout<<"ɾ���ɹ���"<<endl;
            return;
        }
        else{
            p=p->next;
        }
    }
    cout<<"�����ڸ�ID��ѧ����"<<endl;
}

// ��
void find()
{
    cout<<"��������Ҫ��ѯѧ����ID��"<<endl;
    int id;
    cin>>id;
    Node *p=head;
    while(p)
    {
        if(p->stu.id==id){
            cout<<"��ѯ�ɹ���"<<endl;
            cout<<p->stu.name<<"\t"<<p->stu.sex<<"\t"<<p->stu.id<<endl;
            return;
        }
        else p=p->next;
    }
    cout<<"�����ڸ�ID��ѧ����"<<endl;
}

// ��
void update()
{
    cout<<"��������Ҫ���ĵ�ѧ��ID��"<<endl;
    int id;
    cin>>id;
    Node *p=head;
    while(p)
    {
        if(p->stu.id==id){
            cout<<"��������ĺ��ѧ���������Ա�ѧ�ţ�"<<endl;
            scanf("%s %s %d",p->stu.name,p->stu.sex,&p->stu.id);
            cout<<"���ĳɹ���"<<endl;
            return;
        }
        else p=p->next;
    }
    cout<<"�����ڸ�ID��ѧ����"<<endl;
}

// ��������Ϣ���ص��ļ���
void save()
{
    Node *p=head;
    if((fp=fopen("student.txt","w"))==nullptr)
    {
        cout<<"�ļ�����ʧ�ܣ����ܻ���ļ������"<<endl;
        system("pause");
        return;
    }
    while (p != NULL)
	{
        // ��������Ϣ�������ļ���
		fprintf(fp, "%s %s %d\n", p->stu.name, p->stu.sex, p->stu.id);
		p = p->next;
	}
    fclose(fp);
    cout<<"����ɹ���"<<endl;
    system("pause");
    system("cls");
}

// ���ļ���Ϣ������������
void LoadDate()
{
    if ((fp = fopen("student.txt", "a+"))==nullptr)
	{
		printf("\n�ļ���ʧ�ܣ����ܻ���ļ������\n");
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
        else{   // ͷ�巨
            Node *tmp=head->next;
            p->next=tmp;
            head->next=p;
        }
    }
    fclose(fp);
    cout<<"���سɹ���"<<endl;
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