#include "seqlist.h"
void Testseqlist1() {
	Seqlist s;
	SeqListInit(&s);
	SeqListPrint(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);//123

	SeqListpopBack(&s);//12
	
	SeqListPushFront(&s, 0);//012;

	SeqListPopFront(&s);
	SeqListPrint(&s);
}
int main()
{
	Testseqlist1();
	return 0;
}
