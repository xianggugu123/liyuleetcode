//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

#include <iostream>
using namespace std;
#include<vector>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* insert(TreeNode* root,int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }
        return root;
    }
 
    void traversal(TreeNode* cur, vector<int>& res) {
        if (!cur) {
            return;
        }
        res.push_back(cur->val);
        traversal(cur->left, res);
        traversal(cur->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        traversal(root, res);
        for (auto i : res) {
            cout << i << ' ';
        }
        cout << endl;
        return res;
    }
};
//int main()
//{
//    Solution a;
//    TreeNode* root = nullptr;
//    root = a.insert(root, 1);
//    root = a.insert(root, NULL);
//    root = a.insert(root, 2);
//    root = a.insert(root, 3);
//    a.preorderTraversal(root);
//          
//   
//	return 0;
//}
