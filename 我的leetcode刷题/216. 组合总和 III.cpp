#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>>result;
    vector<int>path;

    void backTracking(int n, int k, int sum, int indexStart) {
        if (sum > n) {
            return;
        }
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);

            }
            return;

        }
        for (int i = indexStart; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backTracking(n, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(n, k, 0, 1);
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
    int n = 9, k = 3;
    vector<vector<int>>result = a.combinationSum3(k, n);
    a.print(result);
    return 0;
}
