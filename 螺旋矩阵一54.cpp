//54. 螺旋矩阵
//
//
//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//
//示例 1：
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//
//示例 2：
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//
//
//提示：
//
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 10
//- 100 <= matrix[i][j] <= 100
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right&& top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        for (auto &i : order)
        {
            cout << order[i] << " ";
        }
        cout << endl;
       
        return order;
    }
};
//int main()
//{
//    Solution a;
//    vector <vector<int> >array;
//    std::vector<int> v;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            int value;
//            cin >> value;
//            v.push_back(value);
//        }
//        array.push_back(v); //保存array的每个元素
//        v.clear();
//    }
//   
//    a.spiralOrder(array);
//    
//	return 0;
//}
