//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
#include <iostream>
using namespace std;
#include<queue>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) :val(val), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    ///*TreeNode* insert(TreeNode* root, int val) {
    //    if (root == nullptr) {
    //        return new TreeNode(val);
    //    }
    //    else {
    //        root->left = insert(root->left, val);
    //        root->right = insert(root->right, val);
    //    }
    //    return root;*/
    //}
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<vector<int>>result;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            vector<int>vec;
            while (size--)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }

            }
            result.push_back(vec);

        }
        reverse(result.begin(), result.end());
        for (auto i : result) {
            for (auto j : i) {
                if (j != 0) {
                    cout << j << ' ';
                }

            }
            cout << endl;
        }
        return result;
    }
};
//int main()
//{
//    Solution a;
//    TreeNode* root = nullptr;
//    /* root = a.insert(root, 3);
//     root = a.insert(root, 9);
//     root = a.insert(root, 20);
//     root = a.insert(root, NULL);
//     root = a.insert(root, NULL);
//     root = a.insert(root, 15);
//     root = a.insert(root, 7);
//     a.levelOrder(root);*/
//
//
//
//    return 0;
//}
