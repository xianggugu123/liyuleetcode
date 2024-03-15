//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size() - 1;
        char* left = &s[0];
        char* right = &s[sz];
        while (left < right) {
            char temp = 0;
            temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
        for (auto i : s) {
            cout << i << ' ';
        }
        cout << endl;

    }
};
//int main()
//{
//    Solution a;
//    vector<char> s = { 'h', 'e','l','l','o' };
//    a.reverseString(s);
//	return 0;
//}
