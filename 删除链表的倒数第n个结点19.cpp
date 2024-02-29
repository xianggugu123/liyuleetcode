#include <iostream>
using namespace std;
#include <list>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        ++n;
        while (n-- && fast != nullptr) {
            fast = fast->next;

        }
        while (fast) {

            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        temp = nullptr;
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
//int main()
//{
//    Solution a;
//    list<int> p = { 1,2,3,4,5 };
//
//    ListNode* head = nullptr;
//    ListNode* cur = nullptr;
//    for (int val : p) {
//
//        if (head == nullptr)
//        {
//            head = new ListNode(val);
//            cur = head;
//        }
//        else
//        {
//            cur->next = new ListNode(val);
//            cur = cur->next;
//        }
//    }
//    a.print(head);
//    ListNode* heiheiihei = a.removeNthFromEnd(head,5);
//    a.print(heiheiihei);
//    
//    return 0;
//}
