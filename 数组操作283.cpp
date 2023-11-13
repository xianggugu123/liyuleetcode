//283. 移动零
//
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//
//示例 1:
//输入: nums = [0, 1, 0, 3, 12]
//输出 : [1, 3, 12, 0, 0]
//
//示例 2 :
//    输入 : nums = [0]
//    输出 : [0]
//
//提示:
//
//    1 <= nums.length <= 104
//        - 231 <= nums[i] <= 231 - 1
//        进阶：你能尽量减少完成的操作次数吗？

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int>& moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
            }
        }
        for (slow; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        return nums;
    }
};
//int main()
//{
//    vector<int>nums{0, 1, 0, 3, 12};
//    Solution a;
//    a.moveZeroes(nums);
//	return 0;
//}
