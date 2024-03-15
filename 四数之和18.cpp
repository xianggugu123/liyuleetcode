#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && (nums[i] >= 0)) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {

                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && (nums[i] + nums[j] == nums[i] + nums[j - 1]))
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {

                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
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

        return res;
    }
};
//int main()
//{
//    Solution a;
//    vector<int>nums = { 1,0,-1,0,-2,2 };
//    int target = 0;
//    vector<vector<int>>res=a.fourSum(nums, target);
//    a.print(res);
//	return 0;
//}
