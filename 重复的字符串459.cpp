/*给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成*/

#include <iostream>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != string::npos) {
            cout << true;
            return true;
        }
        return false;
    }
};
int main()
{
    string s = "abab";
    Solution a;
    a.repeatedSubstringPattern(s);
	return 0;
}
