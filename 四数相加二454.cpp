//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组(i, j, k, l) 能满足：
//
//0 <= i, j, k, l < n
//    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int fourNumSum(vector<int>&nums1, vector<int>&nums2, vector<int>&nums3, vector<int>&nums4) {
		unordered_map<int, int>map;
		for (auto i : nums1) {
			for (auto k : nums2) {
				map[i + k]++;
			}
		}
		int count = 0;
		for (auto j : nums3) {
			for (auto l : nums4) {
				if (map.find(0 - (j + l)) != map.end()) {
					count += map[0 - (j + l)];
				}
			}
		}
		cout << count << endl;
		return count;
	}
};
//int main()
//{
//	Solution a;
//	vector<int>nums1 = { 1,2 };
//	vector<int>nums2 = { -2,-1 };
//	vector<int>nums3 = { -1,2 };
//	vector<int>nums4 = { 0,2 };
//	
//	
//	a.fourNumSum(nums1,nums2,nums3,nums4);
//	
//	return 0;
//}
