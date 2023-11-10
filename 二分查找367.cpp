//给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
//完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
//不能使用任何内置的库函数，如  sqrt 。
//
//示例 1：
//输入：num = 16
//输出：true
//解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
//示例 2：
//输入：num = 14
//输出：false
//解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
//
//提示：
//1 <= num <= 231 - 1

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;
        while (l <= r)
        {
            int middle = l + (r - l) / 2;
            if ((long long)middle * middle < num)
            {
                l = middle + 1;
            }
            else if ((long long)middle * middle > num)
            {
                r = middle - 1;
            }
            else
            {
                cout << "true" << endl;
                return true;
            }
        }
        cout << "false" << endl;
        return false;
    }
};
int main()
{
    int x_1 = 4;
    int x_2 = 8;
    Solution a;
    a.isPerfectSquare(x_1);
    a.isPerfectSquare(x_2);
	return 0;
}
