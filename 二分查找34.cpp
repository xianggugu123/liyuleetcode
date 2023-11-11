#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int leftBoard = getLeftBoard(nums, target);
		int rightBoard = getRightBorder(nums, target);
		if (leftBoard == -2 || rightBoard == -2)
		{
			cout << "{"<<-1<<","<<-1<<"}"<< endl;
			return { -1,-1 };
		}
		else if (rightBoard - leftBoard > 1)
		{
			cout << "{" << leftBoard + 1 << "," << rightBoard - 1 << "}" << endl;
			return { leftBoard + 1, rightBoard - 1 };
		}
			
		else
		{
			cout << "{" << -1 << "," << -1 << "}" << endl;
			return { -1,-1 };
		}
		
	}

private:
	int getRightBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int rightborder = -2;
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] > target)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
				rightborder = left;
			}
		}
		return rightborder;
	}
	int getLeftBoard(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int leftBoard = -2;
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] < target)
			{
				left = middle + 1;

			}
			else
			{
				right = middle - 1;
				leftBoard = right;
			}

		}
		return leftBoard;
	}
};
int main()
{
	vector<int> nums{ -1, 0, 3,3,3,3,3,3,5, 9, 12 };
	int target = 3;
	Solution a;
	a.searchRange(nums, target);
	return 0;
}
