//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//
//示例：
//
//输入："abbaca"
//输出："ca"
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (auto i : s) {
            if (st.empty() || st.top() != i) {
                st.push(i);
            }
            else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        for (auto i : res) {
            cout << i;
        }
        cout << endl;
        return res;
    }
};
//int main()
//{
//    Solution a;
//    string s = "abbaca";
//    a.removeDuplicates(s);
//	return 0;
//}
