#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr)
            return result;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(sum / size);
        }

        return result;
    }

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

    // 递归释放节点
    void deleteTree(TreeNode* node) {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    Solution solution;
    vector<int> vals = { 3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1 }; // 用 -1 表示空节点
    int index = 0;
    TreeNode* root = solution.buildTree(vals, index);
    vector<double> averages = solution.averageOfLevels(root);

    for (double avg : averages) {
        cout << avg << " ";
    }
    cout << endl;

    // 释放内存，避免内存泄漏
    solution.deleteTree(root);

    return 0;
}
