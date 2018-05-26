#pragma once
#include <stdio.h>
#include <stdint.h>
#define BitMapType uint64_t//定义uint64_t的目的是为了代码的可移植性

typedef struct BitMap {
    BitMapType* data;
    uint64_t capacity;//代表位图总位数

} BitMap;//定义位图

void BitMapInit(BitMap* bm);//初始化位图

void BitMapSet(BitMap* bm, uint64_t index);//设置某一位为1

void BitMapUnSet(BitMap* bm, uint64_t index);//设置某一位为0

int BitMapTest(BitMap* bm, uint64_t index);//测验某一位是不是1

void BitMapDestroy(BitMap* bm);//销毁位图

void BitMapFill(BitMap* bm);//全部置为1

void BitMapEmpty(BitMap* bm);//全部置为0
