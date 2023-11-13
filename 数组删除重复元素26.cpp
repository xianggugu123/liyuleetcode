#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        cout << slow << endl;
        return slow;
    }
};
//int main()
//{
//    vector<int>nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//    Solution a;
//    a.removeDuplicates(nums);
//	return 0;
//}
