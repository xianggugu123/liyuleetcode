#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (auto& c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};


//int main()
//{
//    string a = "aa";
//    string b = "aab";
//    Solution pp;
//    pp.canConstruct(a, b);
//	return 0;
//}
