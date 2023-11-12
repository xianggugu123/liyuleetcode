//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
//注意：如果对空文本输入退格字符，文本继续为空。
//示例 1：

//输入：s = "ab#c", t = "ad#c"
//输出：true
//解释：s 和 t 都会变成 "ac"。

//示例 2：

//输入：s = "ab##", t = "c#d#"
//输出：true
//解释：s 和 t 都会变成 ""。

//示例 3：
//
//输入：s = "a#c", t = "b"
//输出：false
//解释：s 会变成 "c"，但 t 仍然是 "b"。

//提示：
//
//1 <= s.length, t.length <= 200
//s 和 t 只含有小写字母以及字符 '#'

#include <iostream>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i =S.size()-1, j = T.size()-1;
        int Snum = 0, Tnum = 0;
        while (1)
        {
            while (i >= 0)
            {
                if (S[i] == '#')
                {
                    ++Snum;
                   
                }
                else
                {
                    if (Snum > 0)
                    {
                        --Snum;
                    }
                    else
                    {
                        break;
                    }
                }
                --i;
            }
            while (j >= 0)
            {
                if (T[j] == '#')
                {
                    ++Tnum;
                    
                }
                else
                {
                    if (Tnum > 0)
                    {
                        --Tnum;
                    }
                    else
                    {
                        break;
                    }
                }
                --j;
            }
            if (i < 0 || j < 0)
            {

                break;
            }
            if (S[i] != T[j])
            {
                return false;
            }
           
            --i, --j;
        }
        if (i == -1 && j == -1)
        {
            return true;
        }
        return false;

    }
};
int main()
{
    string s = "a#c", t = "b";
    Solution a;
    a.backspaceCompare(s, t);
	return 0;
}
