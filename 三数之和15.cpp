//给你⼀个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出
//所有满⾜条件且不重复的三元组。
//注意： 答案中不可以包含重复的三元组。
//示例：
//给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//满⾜要求的三元组集合为：
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//输入：nums = [-1, 0, 1, 2, -1, -4]
//输出： [[-1, -1, 2], [-1, 0, 1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是[-1, 0, 1] 和[-1, -1, 2] 。
//注意，输出的顺序和三元组的顺序并不重要。
class Solution {
public:
	void print(vector<vector<int>>& nums) {
		for (auto i : nums) {
			for (auto j : i) {
				cout << j << ' ';
			}
			cout << endl;
		}
		
	}
	vector<vector<int>>threeNumSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) {
				return res;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else {
					res.push_back(vector<int> {nums[i], nums[left], nums[right]});
					while (left < right && nums[right] == nums[right - 1]) {
						right--;
					}
					while (left < right && nums[left] == nums[left + 1]) {
						left++;
					}
					left++;
					right--;
				}
			}

		}
		
	}
};
int main()
{
	vector<int>nums = { -1, 0, 1, 2, -1, -4 };
	Solution a;
	vector<vector<int>> res=a.threeNumSum(nums);
	a.print(res);
	return 0;

}
