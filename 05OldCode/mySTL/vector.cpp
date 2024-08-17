#include <memory>
#include <algorithm>

template <class T,class Alloc>
class vector{
public:
    //vector��Ԫ�����Ͷ���
    typedef T value_type;                   //Ԫ��ֵ����
    typedef value_type* pointer;            //ָ������
    typedef value_type* iterator;           //����������
    typedef value_type& reference;          //��������
    typedef size_t size_type;               //�޷�������
    typedef ptrdiff_t difference_type;      //d������֮��ľ���

protected:
    //STL�ռ�������
    typedef simple_alloc<value_type,Alloc> data_allocator;

    //�������ķ�Χ
    iterator start;
    iterator finish;
    iterator end_of_storage;

    void insert_aux(iterator position,const T& x);

    void deallocate(){//��������
        if(start)data_allocator::deallocate(start,end_of_storage-start);
    }

    void fill_initialize(size_type n,const T& vaule){
        start=allocate_and_fill(n,vaule);
        finish=start+n;
        end_of_storage=finish;
    }

public:
    //�����β������
    iterator begin(){return start;}
    iterator end(){return finish;}

    //�����Ĵ�С�Լ��±��������Ԫ��
    size_type size(){return size_type(end()-begin());}
    size_type capacity()const{return end_of_storage -begin();}
    bool empty()const{return begin()==end();}
    reference operator[](size_type n){return (*begin()+n);}

    //�����Ĺ��캯��
    vector():start(0),finish(0),end_of_storage(0){}
    vector(size_type n,value_type T& value){fill_initialize(n,value);}
    vector(int n,const T& value){fill_initialize(n,value);}
    vector(long n,const T& value){fill_initialize(n,value);}
    explicit vector(size_type n){fill_initialize(n,T());}

    //��������������
    ~vector(){
        destroy(start,finish);  //��������
        deallocate();           //�ͷ��ڴ�
    }

    //������������βԪ��
    reference front(){return *begin();}
    reference back(){return *(end()-1);}

    //��β�����Ԫ��
    void push_back(const T& x){
        if(finish!=end_of_storage){
            construct(finish,x);
            ++finish;
        }
        else{
            insert_aux(end(),x);
        }
    }

    //��β��ɾ��Ԫ��
    void pop_back(){
        --finish;
        destroy(finish);
    }

    iterator erase(iterator position){//����ĳλ���ϵ�Ԫ��
        if(position+1!=end())
            copy(position+1,finish,position);
        --finish;
        destroy(finish);
        return position;
    }

    void resize(size_type new_size,const T& x){
        if(new_size<size())erase(begin()+new_size,end());
        else insert(end(),new_size-size(),x);
    }

    
};