// GFG Problem
// Maximum difference between pair in a matrix -> https://www.geeksforgeeks.org/problems/maximum-difference-between-pair-in-a-matrix/1

// Question Description

// Given an N x N matrix, mat[N][N] of integers. The task is to find the maximum value of mat(c, d) mat(a, b) over all choices of indexes such that both c > a and d > b.

// Example 1:

// Input:
// mat[N][N] = {{ 1, 2, -1, -4, -20 },
//              { -8, -3, 4, 2, 1 },
//              { 3, 8, 6, 1, 3 },
//              { -4, -1, 1, 7, -6 },
//              { 0, -4, 10, -5, 1 }};
// Output: 18
// Explanation: The maximum value is 18 as mat[4][2]
// - mat[1][0] = 18 has maximum difference.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMaxValue() which takes a matrix mat and returns an integer as output.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 <= N <= 103
// -103<= mat[i][j] <=103

// ********** Solution **********

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findMaxValue(vector<vector<int>> &mat, int N)
    {
        // Write your code here

        // T.C -> O(N^2)
        // S.C -> O(N^2)

        vector<vector<int>> compute(N, vector<int>(N, 0));

        compute[N - 1][N - 1] = mat[N - 1][N - 1];

        for (int i = N - 2; i >= 0; i--)
        {
            compute[N - 1][i] = max(compute[N - 1][i + 1], mat[N - 1][i]);
            compute[i][N - 1] = max(compute[i + 1][N - 1], mat[i][N - 1]);
        }

        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = N - 2; j >= 0; j--)
            {
                compute[i][j] = max({compute[i + 1][j], compute[i][j + 1], mat[i][j]});
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                ans = max(ans, compute[i + 1][j + 1] - mat[i][j]);
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
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.findMaxValue(mat, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends