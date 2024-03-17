
#include <iostream>
#include <vector>
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
    void aversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        aversal(root->left, result);
        aversal(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        aversal(root, result);
        return result;
    }
};
//int main()
//{
//	return 0;
//}
