//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//root = [1, null, 3, 2, 4, null, 5, 6]
#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int val;  //节点数值
	vector<Node*>children;
	Node(int _val,vector<Node*>_children){
		val = val;
		
		children = _children;
	}
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*>que;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            vector<int>vec;

            for (int i = 0; i < size; i++) {
                Node* temp = que.front();
                que.pop();
                vec.push_back(temp->val);
                for (int i = 0; i < temp->children.size(); i++) {
                    if (temp->children[i]) que.push(temp->children[i]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
//int main()
//{
//	Solution a;
//	vector<int>vals{1, -1, 3, 2, 4, -1, 5, 6};
//	int index = 0;
//	Node* root = a.buildTree(vals, index);
//	return 0;
//}
