/*给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成*/

#include <iostream>
using namespace std;
class Solution {
public:
    void getNext(int* next, const string& s) {


        int j = -1;
        next[0] = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[j + 1] != s[i]) {
                j = next[j];
            }
            if (s[j + 1] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[100];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};
//int main()
//{
//    string s = "abab";
//    Solution a;
//    a.repeatedSubstringPattern(s);
//	return 0;
//}
