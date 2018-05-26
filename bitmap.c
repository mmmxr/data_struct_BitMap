#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"
#define BitMapSize 100;

uint64_t GetSize(uint64_t index)
{
    return index/(sizeof(BitMapType)*8)+1;
}
void BitMapInit(BitMap* bm)
{
    if(bm==NULL)
    {
        return;
    }
    bm->capacity=BitMapSize;
    uint64_t size=GetSize(bm->capacity);
    bm->data=(BitMapType*)malloc(sizeof(BitMapType)*size);
    memset(bm->data,0,sizeof(BitMapType)*size);
}
int BitMapTest(BitMap* bm, uint64_t index)
{
    if(bm==NULL)
    {
        return -1;
    }
    uint64_t offset=GetSize(index);
    uint64_t size=index%(sizeof(BitMapType)*8);
    uint64_t ret=(bm->data[offset]&(0x1ul<<size));
    return ret>0?1:0;
    
}
void BitMapSet(BitMap* bm, uint64_t index)
{
    if(bm==NULL)
    {
        return;
    }
    if(index>bm->capacity)
    {
        return;
    }
    uint64_t offset=GetSize(index);
    uint64_t size=index % (sizeof(BitMapType)*8);

    bm->data[offset]|=(0x1ul<<size);
}

void BitMapUnSet(BitMap* bm, uint64_t index)
{
    if(bm==NULL)
    {
        return;
    }
    if(index>bm->capacity)
    {
        return;
    }
    uint64_t offset=GetSize(index);
    uint64_t size=index % (sizeof(BitMapType)*8);
    
    bm->data[offset]&=~(0x1ul<<size);

}
void BitMapDestroy(BitMap* bm)
{
        if(bm==NULL)
        {
            return;
        }
        bm->capacity=0;
        free(bm->data);
        bm->data=NULL;
}
void BitMapFill(BitMap* bm)
{
    if(bm==NULL)
    {
        return;
    }
    memset(bm->data,0xff,bm->capacity);
}
void BitMapEmpty(BitMap* bm)
{
    if(bm==NULL)
    {
        return;
    }
    memset(bm->data,0x0,bm->capacity);
}
////////////////////////////////////////
//测试代码
////////////////////////////////////////
#define TEST_HEADER printf("\n======================%s=====================\n",__FUNCTION__)
void TestInit()
{
    TEST_HEADER;
    BitMap bm;
    BitMapInit(&bm);
    BitMapDestroy(&bm);
}
void TestSet()
{
    TEST_HEADER;
    BitMap bm;
    BitMapInit(&bm);
    BitMapSet(&bm,4);
    int ret=BitMapTest(&bm,4);
    printf("ret expect 1,actual %d\n",ret);

}
void TestUnSet()
{
    TEST_HEADER;
    BitMap bm;
    BitMapInit(&bm);
    BitMapUnSet(&bm,4);
    int ret=BitMapTest(&bm,4);
    printf("ret expect 0,actual %d\n",ret);

}
void TestFill()
{
    TEST_HEADER;
    BitMap bm;
    BitMapInit(&bm);
    BitMapFill(&bm);
    int ret=BitMapTest(&bm,4);
    printf("ret expect 1,actual %d\n",ret);
    ret=BitMapTest(&bm,6);
    printf("ret expect 1,actual %d\n",ret);
    ret=BitMapTest(&bm,8);
    printf("ret expect 1,actual %d\n",ret);
    ret=BitMapTest(&bm,10);
    printf("ret expect 1,actual %d\n",ret);

}
void TestEmpty()
{
    TEST_HEADER;
    BitMap bm;
    BitMapInit(&bm);
    BitMapEmpty(&bm);
    int ret=BitMapTest(&bm,4);
    printf("ret expect 0,actual %d\n",ret);
    ret=BitMapTest(&bm,6);
    printf("ret expect 0,actual %d\n",ret);
    ret=BitMapTest(&bm,8);
    printf("ret expect 0,actual %d\n",ret);
    ret=BitMapTest(&bm,10);
    printf("ret expect 0,actual %d\n",ret);
}
int main()
{
    TestInit();
    TestSet();
    TestUnSet();
    TestFill();
    TestEmpty();
    return 0;
}
