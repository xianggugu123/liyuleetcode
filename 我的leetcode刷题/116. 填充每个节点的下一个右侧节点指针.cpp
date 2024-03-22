//给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
//
//struct Node {
//	int val;
//	Node* left;
//	Node* right;
//	Node* next;
//}
//
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
//初始状态下，所有 next 指针都被设置为 NULL。
#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
    Node(int val):val(val),left(nullptr),right(nullptr),next(nullptr){}
};
class Solution {
public:
    Node* creatTree(vector<int> root, int index) {
        if (index > root.size() || root[index] == -1) {
            return nullptr;
        }
        Node* node = new Node(root[index]);
        index++;
        node->left = creatTree(root, index);
        index++;
        node->right = creatTree(root, index);
        return node;
    }
    void destoryTree(Node* root) {
        if (root == nullptr) {
            return;
        }
        destoryTree(root->left);
        destoryTree(root->right);
        delete root;
    }
    Node* connect(Node* root) {
        //vector<int> result;
        queue<Node*>que;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            Node* nodePre =nullptr;
            Node* node = nullptr;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }
                else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;

                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            node->next = nullptr;
        }
        return root;
    }
    void print(Node* root) {
       
        while (root)
        {
            cout << root->val << ' ';
            root = root->next;
        }
        cout << endl;
    }
};
//int main()
//{
//    vector<int>root = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
//    int index = 0;
//    Solution a;
//    Node* node=a.creatTree(root, index);
//    Node* node1=a.connect(node);
//    a.print(node1);
//    a.destoryTree(node1);
//	return 0;
//}
