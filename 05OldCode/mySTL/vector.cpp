#include <memory>
#include <algorithm>

template <class T,class Alloc>
class vector{
public:
    //vector的元素类型定义
    typedef T value_type;                   //元素值类型
    typedef value_type* pointer;            //指针类型
    typedef value_type* iterator;           //迭代器类型
    typedef value_type& reference;          //引用类型
    typedef size_t size_type;               //无符号类型
    typedef ptrdiff_t difference_type;      //d迭代器之间的距离

protected:
    //STL空间配置器
    typedef simple_alloc<value_type,Alloc> data_allocator;

    //迭代器的范围
    iterator start;
    iterator finish;
    iterator end_of_storage;

    void insert_aux(iterator position,const T& x);

    void deallocate(){//析构容器
        if(start)data_allocator::deallocate(start,end_of_storage-start);
    }

    void fill_initialize(size_type n,const T& vaule){
        start=allocate_and_fill(n,vaule);
        finish=start+n;
        end_of_storage=finish;
    }

public:
    //获得首尾迭代器
    iterator begin(){return start;}
    iterator end(){return finish;}

    //容器的大小以及下标访问容器元素
    size_type size(){return size_type(end()-begin());}
    size_type capacity()const{return end_of_storage -begin();}
    bool empty()const{return begin()==end();}
    reference operator[](size_type n){return (*begin()+n);}

    //容器的构造函数
    vector():start(0),finish(0),end_of_storage(0){}
    vector(size_type n,value_type T& value){fill_initialize(n,value);}
    vector(int n,const T& value){fill_initialize(n,value);}
    vector(long n,const T& value){fill_initialize(n,value);}
    explicit vector(size_type n){fill_initialize(n,T());}

    //容器的析构函数
    ~vector(){
        destroy(start,finish);  //析构对象
        deallocate();           //释放内存
    }

    //访问容器的首尾元素
    reference front(){return *begin();}
    reference back(){return *(end()-1);}

    //在尾部添加元素
    void push_back(const T& x){
        if(finish!=end_of_storage){
            construct(finish,x);
            ++finish;
        }
        else{
            insert_aux(end(),x);
        }
    }

    //在尾部删除元素
    void pop_back(){
        --finish;
        destroy(finish);
    }

    iterator erase(iterator position){//消除某位置上的元素
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