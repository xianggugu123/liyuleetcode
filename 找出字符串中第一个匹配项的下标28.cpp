//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下
//标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回 - 1 。
#include <iostream>
using namespace std;
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的⻓度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[20];
        getNext(next, needle);
        int j = -1; // // 因为next数组⾥记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while (j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环⾥
            }
            if (j == (needle.size() - 1)) { // ⽂本串s⾥出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
//int main()
//{
//    string haystack = "aabaabaafa";
//    string needle = "aabaaf";
//    Solution a;
//    int ret=a.strStr(haystack, needle);
//    cout << ret;
//	return 0;
//}
