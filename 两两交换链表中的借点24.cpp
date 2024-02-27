#include <iostream>
using namespace std;
#include <list>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val):val(val), next(nullptr){}

};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode* temp = cur->next;
			ListNode* temp1 = cur->next->next->next;
			cur->next = cur->next->next;
			cur->next->next = temp;
			cur->next->next->next = temp1;
			cur = cur->next->next;

		}
		return dummyHead->next;
	}
    void print(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;

    }
};
int main()
{
    Solution a;
    list<int> p = { 1,2,3,4,5 };
    
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int val : p) {

        if (head == nullptr)
        {
            head = new ListNode(val);
            cur = head;
        }
        else
        {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }
    a.print(head);
    ListNode* heiheiihei = a.swapPairs(head);
    a.print(heiheiihei);
	return 0;
}
