//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
//示例 1:
//输入: nums = [1, 3, 5, 6], target = 5
//输出 : 2
//示例 2 :
//    输入 : nums = [1, 3, 5, 6], target = 2
//    输出 : 1
//    示例 3 :
//    输入 : nums = [1, 3, 5, 6], target = 7
//    输出 : 4
//提示:
//
//1 <= nums.length <= 104
//- 104 <= nums[i] <= 104
//nums 为 无重复元素 的 升序 排列数组
//- 104 <= target <= 104

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle;

            }
            else if (nums[middle] < target)
            {
                left = middle + 1;

            }
            else
            {   
                cout << middle << endl;
                return middle;
            }
        }
        cout << right << endl;
        return right;
    }

};
int main()
{
    vector<int> nums_1{ 1, 3, 5, 6 };
    int target_1 = 5;
    Solution a;
    a.searchInsert(nums_1, target_1);
	return 0;
}
