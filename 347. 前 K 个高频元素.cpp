#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        //1.统计频率
        unordered_map<int, int>  map;
        for (auto i : nums)
        {
            map[i]++;
        }
        //2.对频率排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison>pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        //3.找出前k个元素
        vector<int>result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

//int main()
//{
//    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
//    int k = 2;
//    Solution a;
//    a.topKFrequent(nums, k);
//	return 0;
//}
