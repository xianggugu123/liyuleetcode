//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {

public:
    TreeNode* createTree(vector<int>vec, int index) {
        if (index >= vec.size() || vec[index] == -1) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(vec[index]);
        index++;
        node->left = createTree(vec, index);

        index++;
        node->right = createTree(vec, index);
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {

        queue<TreeNode*>que;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                swap(node->left, node->right);


                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
    void destoryTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        destoryTree(root->left);
        destoryTree(root->right);
        delete(root);
    }
};
//int main()
//{
//	return 0;
//}
