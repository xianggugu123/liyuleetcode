//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	void swap(string& s,int start, int end) {
		for (int i = start,j=end-1; i < j; i++,j--) {
			int temp = 0;
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			
		}
	}
	string reverseStr(string& s, const int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k <= s.size()) {
				swap(s, i, i + k);
			}
			else {
				swap(s, i, (int)s.size() - 1);
			}
		}
		for (auto i : s) {
			cout << i << ' ';
		}
		cout << endl;
		return s;
	}
};
//int main()
//
//{
//	Solution a;
//	string s{ "abcdefg" };
//	int k = 2;
//	a.reverseStr(s, k);
//	return 0;
//}
