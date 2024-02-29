//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void print(vector<int> nums1) {
        for (int num : nums1) {
            cout << num << " ";
        }
        cout << endl;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        print(vector<int>(result_set.begin(), result_set.end()));
        return vector<int>(result_set.begin(), result_set.end());
    }
};
int main()
{
    vector<int>nums1 = { 1,2,2,1 };
    vector<int>nums2 = { 2,2 };
    Solution a;
    a.intersection(nums1, nums2);
	return 0;
}
