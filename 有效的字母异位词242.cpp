#include <iostream>
using namespace std;
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                cout << "000" << endl;
                return false;
            }
        }
        cout << "666" << endl;
        return true;
    }
};
//int main()
//{
//    Solution a;
//    string s = "anagram";
//    string t = "nagaram";
//    a.isAnagram(s, t);
//	return 0;
//}
