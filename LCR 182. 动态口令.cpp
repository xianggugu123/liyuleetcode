//某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤：
//
//设定一个正整数目标值 target
//将 password 前 target 个字符按原顺序移动至字符串末尾
//
//请返回更新后的密码字符串
#include <iostream>
using namespace std;
class Solution {
public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin(), password.begin() + target);
        reverse(password.begin() + target, password.end());
        reverse(password.begin(), password.end());
        return password;
    }
};
//int main()
//{
//    string password = "s3cur1tyC0d3";
//    int target = 4;
//    Solution a;
//    a.dynamicPassword(password, target);
//	return 0;
//}
