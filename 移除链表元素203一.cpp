//203. 移除链表元素
//简单
//相关标签
//相关企业
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
//
//
//示例 1：
//
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]
//
//示例 2：
//
//输入：head = [], val = 1
//输出：[]
//
//示例 3：
//
//输入：head = [7, 7, 7, 7], val = 7
//输出：[]
//
//
//
//提示：
//
//列表中的节点数目在范围[0, 104] 内
//1 <= Node.val <= 50
//0 <= val <= 50
//

#include <iostream>
#include <list>
using namespace std;

  
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virhead = new ListNode(0);
        virhead->next = head;
        ListNode* cur = virhead;
        while (cur->next!=NULL)
        {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
            
        }
        head = virhead->next;
        delete virhead;
        return head;
    }
};
//int main()
//{
//    list<int> pp = { 1,2,6,5,3,6,5,4 };
//    ListNode* head = nullptr;
//    ListNode* current = nullptr;
//
//    // 遍历整数列表并创建链表节点
//    for (int value : pp) {
//        if (head == nullptr) {
//            // 如果是链表的第一个节点
//            head = new ListNode(value);
//            current = head;
//        }
//        else {
//            // 否则创建新节点，并将其连接到链表
//            current->next = new ListNode(value);
//            current = current->next;
//        }
//    }
//
//    int x = 6;
//    Solution a;
//    a.removeElements(head, x);
//    
//	return 0;
//    //12.7号
//}
