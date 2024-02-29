#include <iostream>
using namespace std;
#include <list>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
  };
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB)
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        while (gap--) {
            curA = curA->next;
        }
        while (curA) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
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

//int main()
//{
//    Solution a;
//    list<int> p1 = { 4,1,8,3,5 };
//    list<int> p2 = { 5,0,1,8,3,5 };
//    ListNode* headA = nullptr;
//    ListNode* headB = nullptr;
//    ListNode* cur = nullptr;
//    for (int val : p1) {
//
//        if (headA == nullptr)
//        {
//            headA = new ListNode(val);
//            cur = headA;
//        }
//        else
//        {
//            cur->next = new ListNode(val);
//            cur = cur->next;
//        }
//    }
//    for (int val : p2) {
//
//        if (headB == nullptr)
//        {
//            headB = new ListNode(val);
//            cur = headB;
//        }
//        else
//        {
//            cur->next = new ListNode(val);
//            cur = cur->next;
//        }
//    }
//    a.print(headA);
//    a.print(headB);
//   
//  
//
//   
//	return 0;
//}
