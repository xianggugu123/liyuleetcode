#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        return slow;
    }
};
int main()
{
    vector<int>nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution a;
    a.removeElement(nums, val);
	return 0;
}
