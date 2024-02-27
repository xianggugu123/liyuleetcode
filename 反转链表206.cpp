#include <iostream>
using namespace std;
#include <list>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) :val(val), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* tmp;
        ListNode* pre = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
        void print(ListNode * head) 
        {
            while (head)
            {
                cout << head->val<<" ";
                head = head->next;
            }
            cout <<  endl;
            
        }  
       
};
int main(){
    Solution a;
    list<int> p = { 1,2,3,4,5 };
    ListNode* cur = nullptr;
    ListNode* head = nullptr;

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
    ListNode* heiheiihei = a.reverseList(head);
    a.print(heiheiihei);
    return 0;
}