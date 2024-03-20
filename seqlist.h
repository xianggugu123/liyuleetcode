#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
typedef int SLDatatype;
//顺序表动态存储
typedef struct Seqlist {
	SLDatatype* array;
	size_t size;
	size_t capicity;
}Seqlist;
//初始化
void SeqListInit(Seqlist* s);
void SeqListPrint(Seqlist* s);
void SeqListPushBack(Seqlist* s, SLDatatype x);
void SeqListpopBack(Seqlist* s);
void SeqListPushFront(Seqlist* s, SLDatatype x);
void SeqListPopFront(Seqlist* s);
void SeqListCheckcapacity(Seqlist* s);