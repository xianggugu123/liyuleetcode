//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//
//你可以按 任何顺序 返回答案。
//n = 4;; k = 2;
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(int n, int k, int indexStart) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = indexStart; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
    void print(vector<vector<int>>& result) {
        for (auto i : result) {
            for (auto j : i) {
                cout << j << ',';
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution a;
    int n = 4, k = 2;
    vector<vector<int>>result=a.combine(n, k);
    a.print(result);
	return 0;
}
