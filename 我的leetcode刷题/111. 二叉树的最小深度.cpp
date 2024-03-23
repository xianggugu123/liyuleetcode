//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明：叶子节点是指没有子节点的节点。
#include <iostream>
#include<queue>
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*>que;
        if (root != nullptr) {
            que.push(root);
        }
        else {
            return 0;
        }
        int deepth = 0;
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    ++deepth;
                    return deepth;
                }
                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }

            }
            ++deepth;
        }
        return deepth;
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

int main()
{
    Solution a;
    vector<int>vec = { 3,9,20,-1,-1,15,7 };
    int index = 0;
    TreeNode* root = a.createTree(vec, index);
    int mindepth = a.minDepth(root);
    cout << mindepth << endl;

    
    return 0;
}
