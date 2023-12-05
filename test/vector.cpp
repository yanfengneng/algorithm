#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
typedef int vectorElemType;

typedef struct vector {
    // 数据成员，外部不可访问
    vectorElemType *elem;   // 数组首地址，初始化开辟 initSize 个空间
    int length;             // 数组当前长度，初始化为 0
    int totalSize;          // 数组总长度，初始化为 initSize

    // 函数成员，外部可访问
    void (*push_back)(struct vector *vct, vectorElemType e);
    void (*push_front)(struct vector *vct, vectorElemType e);
    void (*pop_back)(struct vector *vct);
    void (*pop_front)(struct vector *vct);
    void (*insert)(struct vector *vct, int index, vectorElemType e);
    vectorElemType (*at)(struct vector *vct, int index);
    void (*set)(struct vector *vct, int index, vectorElemType e);
    void (*erase)(struct vector *vct, int index);
    void (*clear)(struct vector *vct);
    bool (*empty)(struct vector *vct);
    int (*size)(struct vector *vct);
    void (*sort)(struct vector *vct, int(*cmp)(const void *a, const void *b));
} vector;

// 外部可访问的函数
void initVector(vector *vct);                                   // 初始化 vector
void destroyVector(vector *vct);                                 // 销毁 vector 空间
void vectorPushBack(vector *vct, vectorElemType e);             // 往 vector 尾部追加 e
void vectorPushFront(vector *vct, vectorElemType e);            // 往 vector 首部添加 e
void vectorPopBack(vector *vct);                                // 弹出数组尾部元素
void vectorPopFront(vector *vct);                               // 弹出数组首元素
void vectorInsert(vector *vct, int index, vectorElemType e);    // 在第 index 个元素之前插入一个数据
vectorElemType vectorAt(vector *vct, int index);                 // 返回第 index 个元素
void vectorSet(vector *vct, int index, vectorElemType e);        // 将第 index 个元素置为 x
void vectorErase(vector *vct, int index);                       // 删除第 index 个元素
void vectorClear(vector *vct);                                  // 清空 vector
bool vectorEmpty(vector *vct);                                   // 判断 vector 是否为空
int vectorSize(vector *vct);                                     // 返回 vector 内元素个数
void vectorSort(vector *vct, int(*cmp)(const void *a, const void *b));
// 用 stdlib.h 中的 qsort 函数给数组内容排序，遗留问题，后面不再支持

// 外部不可访问的函数
bool needIncrease(vector *vct);                                 // 判断是否需要开辟新空间，在添加新元素之前判断
void increase(vector *vct);                                     // 重新开辟 listsize * 2 个空间，复制原数据、销毁原 elem，该函数不允许外部调用

const int initSize = 100;

// 初始化 vector
void initVector(vector *vct) {
    vct->length = 0;
    vct->totalSize = initSize;
    assert(vct->elem = (vectorElemType*)malloc(initSize * sizeof(vectorElemType)));

    vct->push_back = vectorPushBack;
    vct->push_front = vectorPushFront;
    vct->pop_back = vectorPopBack;
    vct->pop_front = vectorPopFront;
    vct->insert = vectorInsert;
    vct->at = vectorAt;
    vct->set = vectorSet;
    vct->erase = vectorErase;
    vct->clear = vectorClear;
    vct->empty = vectorEmpty;
    vct->size = vectorSize;
    vct->sort = vectorSort;
}

// 销毁 vector 空间
void destroyVector(vector *vct) {
    free(vct->elem);
}

// 重新开辟 listsize * 2 个空间，复制原数据、销毁原 elem，该函数不允许外部调用
void increase(vector *vct) {
    vectorElemType *p;
    assert(p = (vectorElemType*)malloc(vct->totalSize * 2 * sizeof(vectorElemType)));
    memcpy(p, vct->elem, sizeof(vectorElemType) * vct->length);
    free(vct->elem);
    vct->elem = p;
    vct->totalSize *= 2;
}

// 往 vector 尾部追加 e
void vectorPushBack(vector *vct, vectorElemType e) {
    vectorInsert(vct, vct->length, e);
}

// 往 vector 首部添加 e
void vectorPushFront(vector *vct, vectorElemType e) {
    vectorInsert(vct, 0, e);
}

// 弹出数组尾部元素
void vectorPopBack(vector *vct) {
    if(vct->length == 0) {
        return ;
    }
    --vct->length;
}

// 弹出数组首元素
void vectorPopFront(vector *vct) {
    if(vct->length == 0) {
        return ;
    }
    vectorErase(vct, 0);
}

// 在第 index 个元素之前插入一个数据
void vectorInsert(vector *vct, int index, vectorElemType e) {
    assert(index >= 0);
    assert(index <= vct->length);

    if(needIncrease(vct)) {
        increase(vct);
    }
    for(int i = vct->length; i > index; --i) {
        vct->elem[i] = vct->elem[i - 1];
    }
    vct->elem[index] = e;
    ++vct->length;
}

// 返回第 index 个元素
vectorElemType vectorAt(vector *vct, int index) {
    assert(index >= 0);
    assert(index < vct->length);

    return vct->elem[index];
}

// 将第 index 个元素置为 x
void vectorSet(vector *vct, int index, vectorElemType e) {
    assert(index >= 0);
    assert(index < vct->length);

    vct->elem[index] = e;
}

// 删除第 index 个元素
void vectorErase(vector *vct, int index) {
    assert(index >= 0);
    assert(index < vct->length);

    for(int i = index + 1; i < vct->length; ++i) {
        vct->elem[i - 1] = vct->elem[i];
    }
    --vct->length;
}

// 清空 vector
void vectorClear(vector *vct) {
    vct->length = 0;
}

// 判断 vector 是否为空
bool vectorEmpty(vector *vct) {
    return vct->length == 0;
}

// 返回 vector 内元素个数
int vectorSize(vector *vct) {
    return vct->length;
}

// 用 stdlib.h 中的 qsort 函数给数组内容排序，遗留问题，后面不再支持
void vectorSort(vector *vct, int(*cmp)(const void *a, const void *b)) {
    qsort(vct->elem, vct->length, sizeof(vectorElemType), cmp);
}

// 判断是否需要开辟新空间，在添加新元素之前判断
bool needIncrease(vector *vct) {
    return vct->length >= vct->totalSize;
}


int main() {
    vector a;
    initVector(&a);
    printf("%d\n", a.length);
    return 0;
}