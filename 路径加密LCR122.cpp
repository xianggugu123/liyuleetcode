//假定一段路径记作字符串 path，其中以 "." 作为分隔符。现需将路径加密，加密方法为将 path 中
//的分隔符替换为空格 " "，请返回加密后的字符串。
#include <iostream>
using namespace std;
class Solution {
public:
    string pathEncryption(string &path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                path[i] = ' ';
            }
            else {
                continue;
            }

        }
        for (auto i : path) {
            cout << i ;
        }
        cout << endl;
        return path;
    }
};
int main()
{
    Solution a;
    string path= "a.aef.qerf.bb";
    a.pathEncryption(path);
	return 0;
}
