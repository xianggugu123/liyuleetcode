//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x** 0.5 。
//
//示例 1：
//输入：x = 4
//输出：2
//示例 2：
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
//
//提示：
//0 <= x <= 231 - 1
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int middle = l + (r - l) / 2;
            if (middle * middle <= x)
            {
                ans = middle;
                l = middle + 1;
            }
            else
            {
                r = middle - 1;
            }
        }
        cout << ans << endl;
        return ans;
    }
};
//int main()
//{
//    int x_1 = 4;
//    int x_2 = 8;
//    Solution a;
//    a.mySqrt(x_1);
//    a.mySqrt(x_2);
//	return 0;
//}
