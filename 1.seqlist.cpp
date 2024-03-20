#include "seqlist.h"
void SeqListInit(Seqlist* s) {
	s->array = new SLDatatype(4);
	if (s->array == nullptr) {
		cout << "开辟空间失败！" << endl;
		exit(-1);
	}
	s->size = 0;
	s->capicity = 4;
}
void SeqListPrint(Seqlist* s) {
	assert(s);
	for (size_t i = 0; i < s->size; i++) {
		cout << s->array[i] << ' ';
	}
	cout << endl;
}
void SeqListPushBack(Seqlist* s, SLDatatype x) {
	assert(s);
	SeqListCheckcapacity(s);
	s->array[s->size] = x;
	s->size++;
}
void SeqListpopBack(Seqlist* s) {
	assert(s);
	s->size--;
}
void SeqListPushFront(Seqlist* s, SLDatatype x) {
	int end = s->size - 1;
	while (end>=0) {
		s->array[end+1] = s->array[end];
		--end;
	}
	
	s->array[0] = x;
	s->size++;
}
void SeqListCheckcapacity(Seqlist* s) {
	//增容
	if (s->size <= s->capicity) {
		s->capicity *= 2;
		s->array = (SLDatatype*)realloc(s->array, sizeof(SLDatatype) * s->capicity);
		if (s->array == nullptr) {
			cout << "增容失败！" << endl;
			exit(-1);
		}
	}
}
void SeqListPopFront(Seqlist* s) {
	for (int i = 0; i < s->size - 1; i++) {
		s->array[i] = s->array[i + 1];
	}
	s->size--;
}