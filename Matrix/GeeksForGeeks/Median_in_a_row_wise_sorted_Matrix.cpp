// GFG Problem
// Median in a row-wise sorted Matrix -> https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Question Description

// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

// Example 1:

// Input:
// R = 3, C = 3
// M = [[1, 3, 5],
//      [2, 6, 9],
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.

// Example 2:

// Input:
// R = 3, C = 1
// M = [[1], [2], [3]]
// Output: 2
// Explanation: Sorting matrix elements gives
// us {1,2,3}. Hence, 2 is median.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

// Expected Time Complexity: O(32 * R * log(C))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= R, C <= 400
// 1 <= matrix[i][j] <= 2000

// ********** Solution **********

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        int ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < R; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count >= (R * C + 1) / 2)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends