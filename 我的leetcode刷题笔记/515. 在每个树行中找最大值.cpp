#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    // 先序遍历构建二叉树
    TreeNode* buildTree(vector<int>& vals, int& index) {
        if (index >= vals.size() || vals[index] == -1) // -1 表示空节点
            return nullptr;
        TreeNode* node = new TreeNode(vals[index]);
        ++index; // 在每次递归调用之后递增 index
        node->left = buildTree(vals, index);
        ++index; // 在每次递归调用之后递增 index
        node->right = buildTree(vals, index);
        return node;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            size_t size = que.size();
            int max = INT_MIN;
            for (size_t i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                max = node->val > max ? node->val : max;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
    // 递归释放节点
    void deleteTree(TreeNode* node) {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};
//int main()
//{
//
//    Solution solution;
//    vector<int> vals = { 1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1}; // 用 -1 表示空节点
//    int index = 0;
//    TreeNode* root = solution.buildTree(vals, index);
//    vector<int> maxValue = solution.largestValues(root);
//
//    for (auto i  : maxValue) {
//        cout << i << " ";
//    }
//    cout << endl;
//
//    // 释放内存，避免内存泄漏
//    solution.deleteTree(root);
//
//    return 0;
//}
