//给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组[numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//
//示例 1：
//输入：target = 7, nums = [2, 3, 1, 2, 4, 3]
//输出：2
//解释：子数组[4, 3] 是该条件下的长度最小的子数组。
//示例 2：
//输入：target = 4, nums = [1, 4, 4]
//输出：1
//示例 3：
//输入：target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
//输出：0
//
//提示：
//
//1 <= target <= 109
//1 <= nums.length <= 105
//1 <= nums[i] <= 105

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int result = nums.size()+1;
        int length = 0;
        for (int j = 0; j <= nums.size() - 1; j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                length = j - i + 1;
                result = min(result, length);
                sum = sum - nums[i];
                ++i;

            }
        }
        cout << (result == nums.size() + 1 ? 0 : result) << endl;
        return result== nums.size() + 1?0:result;
    }
};
//int main()
//{
//    vector<int>nums{1,1,1,1,1,1,1,1};
//    int target = 11;
//    Solution a;
//    a.minSubArrayLen(target,nums);
//	return 0;
//}
