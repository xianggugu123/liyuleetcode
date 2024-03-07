//给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//
//返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
//
//注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string swap(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
    string removeNull(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        return s;
    }
    string reverseWords(string& s) {
        removeNull(s);
        swap(s, 0, int(s.size() - 1));

        int slow = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                swap(s, slow, i - 1);
                slow = i + 1;
            }
        }
        for (auto i : s) {
            cout << i;
        }
        cout << endl;
        return s;
    }
};
int main()
{
    Solution a;
    string s = "the sky is blue";
    a.reverseWords(s);
	return 0;
}
