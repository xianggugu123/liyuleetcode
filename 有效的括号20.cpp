//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>a;
        if (s.size() % 2 != 0) {
            return false;

        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                a.push(')');
            }
            else if (s[i] == '[') {
                a.push(']');
            }
            else if (s[i] == '{') {
                a.push('}');
            }
            else if (a.empty() || s[i] != a.top()) {
                return false;
            }
            else {
                a.pop();
            }
        }
        return a.empty();
    }
};
//int main()
//{
//    Solution a;
//    string pp= "()";
//    int res=a.isValid(pp);
//    if (res == 1) {
//        cout << true << endl;
//    }
//    else {
//        cout << false << endl;
//    }
//	return 0;
//}
