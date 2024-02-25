#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete(tmp);
            tmp = NULL;
        }
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                tmp = NULL;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    

};
int main()
{
    list<int> pp = { 1,2,6,5,3,6,5,4 };
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    // 遍历整数列表并创建链表节点
    for (int value : pp) {
        if (head == nullptr) {
            // 如果是链表的第一个节点
            head = new ListNode(value);
            current = head;
        }
        else {
            // 否则创建新节点，并将其连接到链表
            current->next = new ListNode(value);
            current = current->next;
        }
    }

    int x = 6;
    Solution a;
    a.removeElements(head, x);
  
	return 0;
    //12.7号
}