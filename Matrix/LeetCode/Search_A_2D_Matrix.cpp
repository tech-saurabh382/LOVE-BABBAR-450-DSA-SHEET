// LeetCode Problem
// 74. Search a 2D Matrix -> https://leetcode.com/problems/search-a-2d-matrix/description/

// Question Description

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// ********* Solution **********

class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;

        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currentElement = matrix[rowIndex][colIndex];

            if (currentElement == target)
            {
                return true;
            }
            else if (currentElement > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return false;
    }
};