//59. 螺旋矩阵 II
//
//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
//示例 1：
//输入：n = 3
//输出： [[1, 2, 3], [8, 9, 4], [7, 6, 5]]
//
//示例 2：
//
//输入：n = 1
//输出： [[1]]
//
//提示：
//1 <= n <= 20

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generateMatrix (int n)
	{
		int startx = 0, starty = 0;
		int offset = 1;
		int num = 1;
		int loop = n / 2;
		int mid = n / 2;
		int i , j ;
		vector<vector<int> >matrix(n, vector<int>(n, 0));
		while (loop--)
		{
			for (j = starty; j < n - offset; j++) {
				matrix[startx][j] = num++;
			}
			for (i = startx; i < n - offset; i++) {
				matrix[i][j] = num++;
			}
			for (; j > starty; j--) {
				matrix[i][j] = num++;
			}
			for (; i > startx; i--) {
				matrix[i][j] = num++;
			}
			++startx;
			++starty;
			offset+=1;
		}
		if (n % 2)
		{
			matrix[mid][mid] = num;
		}
		for (int i = 0; i != matrix.size(); i++)
		{
			for (int j = 0; j != matrix[0].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		
		return matrix;
	}
};
//int main()
//{
//	Solution a;
//	int m = 4;
//	a.generateMatrix(m);
//	return 0;
//}
