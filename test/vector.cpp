#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
typedef int vectorElemType;

typedef struct vector {
    // ���ݳ�Ա���ⲿ���ɷ���
    vectorElemType *elem;   // �����׵�ַ����ʼ������ initSize ���ռ�
    int length;             // ���鵱ǰ���ȣ���ʼ��Ϊ 0
    int totalSize;          // �����ܳ��ȣ���ʼ��Ϊ initSize

    // ������Ա���ⲿ�ɷ���
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

// �ⲿ�ɷ��ʵĺ���
void initVector(vector *vct);                                   // ��ʼ�� vector
void destroyVector(vector *vct);                                 // ���� vector �ռ�
void vectorPushBack(vector *vct, vectorElemType e);             // �� vector β��׷�� e
void vectorPushFront(vector *vct, vectorElemType e);            // �� vector �ײ���� e
void vectorPopBack(vector *vct);                                // ��������β��Ԫ��
void vectorPopFront(vector *vct);                               // ����������Ԫ��
void vectorInsert(vector *vct, int index, vectorElemType e);    // �ڵ� index ��Ԫ��֮ǰ����һ������
vectorElemType vectorAt(vector *vct, int index);                 // ���ص� index ��Ԫ��
void vectorSet(vector *vct, int index, vectorElemType e);        // ���� index ��Ԫ����Ϊ x
void vectorErase(vector *vct, int index);                       // ɾ���� index ��Ԫ��
void vectorClear(vector *vct);                                  // ��� vector
bool vectorEmpty(vector *vct);                                   // �ж� vector �Ƿ�Ϊ��
int vectorSize(vector *vct);                                     // ���� vector ��Ԫ�ظ���
void vectorSort(vector *vct, int(*cmp)(const void *a, const void *b));
// �� stdlib.h �е� qsort �������������������������⣬���治��֧��

// �ⲿ���ɷ��ʵĺ���
bool needIncrease(vector *vct);                                 // �ж��Ƿ���Ҫ�����¿ռ䣬�������Ԫ��֮ǰ�ж�
void increase(vector *vct);                                     // ���¿��� listsize * 2 ���ռ䣬����ԭ���ݡ�����ԭ elem���ú����������ⲿ����

const int initSize = 100;

// ��ʼ�� vector
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

// ���� vector �ռ�
void destroyVector(vector *vct) {
    free(vct->elem);
}

// ���¿��� listsize * 2 ���ռ䣬����ԭ���ݡ�����ԭ elem���ú����������ⲿ����
void increase(vector *vct) {
    vectorElemType *p;
    assert(p = (vectorElemType*)malloc(vct->totalSize * 2 * sizeof(vectorElemType)));
    memcpy(p, vct->elem, sizeof(vectorElemType) * vct->length);
    free(vct->elem);
    vct->elem = p;
    vct->totalSize *= 2;
}

// �� vector β��׷�� e
void vectorPushBack(vector *vct, vectorElemType e) {
    vectorInsert(vct, vct->length, e);
}

// �� vector �ײ���� e
void vectorPushFront(vector *vct, vectorElemType e) {
    vectorInsert(vct, 0, e);
}

// ��������β��Ԫ��
void vectorPopBack(vector *vct) {
    if(vct->length == 0) {
        return ;
    }
    --vct->length;
}

// ����������Ԫ��
void vectorPopFront(vector *vct) {
    if(vct->length == 0) {
        return ;
    }
    vectorErase(vct, 0);
}

// �ڵ� index ��Ԫ��֮ǰ����һ������
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

// ���ص� index ��Ԫ��
vectorElemType vectorAt(vector *vct, int index) {
    assert(index >= 0);
    assert(index < vct->length);

    return vct->elem[index];
}

// ���� index ��Ԫ����Ϊ x
void vectorSet(vector *vct, int index, vectorElemType e) {
    assert(index >= 0);
    assert(index < vct->length);

    vct->elem[index] = e;
}

// ɾ���� index ��Ԫ��
void vectorErase(vector *vct, int index) {
    assert(index >= 0);
    assert(index < vct->length);

    for(int i = index + 1; i < vct->length; ++i) {
        vct->elem[i - 1] = vct->elem[i];
    }
    --vct->length;
}

// ��� vector
void vectorClear(vector *vct) {
    vct->length = 0;
}

// �ж� vector �Ƿ�Ϊ��
bool vectorEmpty(vector *vct) {
    return vct->length == 0;
}

// ���� vector ��Ԫ�ظ���
int vectorSize(vector *vct) {
    return vct->length;
}

// �� stdlib.h �е� qsort �������������������������⣬���治��֧��
void vectorSort(vector *vct, int(*cmp)(const void *a, const void *b)) {
    qsort(vct->elem, vct->length, sizeof(vectorElemType), cmp);
}

// �ж��Ƿ���Ҫ�����¿ռ䣬�������Ԫ��֮ǰ�ж�
bool needIncrease(vector *vct) {
    return vct->length >= vct->totalSize;
}


int main() {
    vector a;
    initVector(&a);
    printf("%d\n", a.length);
    return 0;
}