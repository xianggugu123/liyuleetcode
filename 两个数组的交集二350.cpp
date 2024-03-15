//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素
//在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Soluction {
public:
	void print(vector<int> nums1) {
		for (int num : nums1) {
			cout << num << " ";
		}
		cout << endl;
	}
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() < nums2.size()) {
			return intersect(nums2, nums1);
		}
		unordered_map<int, int> m;
		for (auto num : nums1) {			
				++m[num];			
		}
		vector<int> res;
		for (auto num : nums2) {
			if (m.find(num) != m.end()) {
				res.push_back(num);
				--m[num];
				if (m[num] == 0) {
					m.erase(num);
				}
			}
		}
		print(vector<int>(res.begin(), res.end()));
		return res;
	}
};
//int main()
//{
//	vector<int>nums1 = { 1,2,2,1 };
//	vector<int>nums2 = { 2,2 };
//	Soluction a;
//	a.intersect(nums1, nums2);
//	
//	return 0;
//}
