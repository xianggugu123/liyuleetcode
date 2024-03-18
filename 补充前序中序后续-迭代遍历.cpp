#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//前序遍历
//class Solution {
//public:
//
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int>result;
//        stack<TreeNode*>li;
//        if (root == nullptr) {
//            return result;
//        }
//        li.push(root);
//        while (!li.empty()) {
//            TreeNode* node = li.top();
//            if (node != nullptr) {
//                li.pop();
//                if (node->right) {
//                    li.push(node->right);
//                }
//                if (node->left) {
//                    li.push(node->left);
//                }
//                li.push(node);
//                li.push(nullptr);
//            }
//            else {
//                li.pop();
//                node = li.top();
//                li.pop();
//                result.push_back(node->val);
//            }
//
//
//        }
//        return result;
//    }
//};

//中序遍历

//class Solution {
//public:
//
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int>result;
//        stack<TreeNode*>li;
//        if (root == nullptr) {
//            return result;
//        }
//        li.push(root);
//        while (!li.empty()) {
//            TreeNode* node = li.top();
//            if (node != nullptr) {
//                li.pop();
//                if (node->right) {
//                    li.push(node->right);
//                }
//
//                li.push(node);
//                li.push(nullptr);
//
//                if (node->left) {
//                    li.push(node->left);
//                }
//            }
//            else {
//                li.pop();
//                node = li.top();
//                li.pop();
//                result.push_back(node->val);
//            }
//
//
//        }
//        return result;
//    }
//};

//后序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if (root != nullptr) {
            st.push(root);
        }

        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right) {
                    st.push(node->right);
                }
                if (node->left) {
                    st.push(node->left);
                }
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;

    }
};
//int main()
//{
//	return 0;
//}
