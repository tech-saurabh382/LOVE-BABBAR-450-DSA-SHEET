// GFG Problem
// Rotate by 90 degree -> https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

// Question Description

// Given a square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.

// Example 1:

// Input:
// N = 3
// matrix[][] = {{1, 2, 3},
//               {4, 5, 6}
//               {7, 8, 9}}
// Output:
// Rotated Matrix:
// 3 6 9
// 2 5 8
// 1 4 7
// Example 2:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output:
// Rotated Matrix:
// 2 4
// 1 3

// Your Task:
// You dont need to read input or print anything. Complete the function rotateby90() which takes the matrix as input parameter and rotates it by 90 degrees in anti-clockwise direction without using any extra space. You have to modify the input matrix in-place.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 100
// 1 <= matrix[][] <= 1000

// Company Tags

// Paytm Microsoft Samsung Adobe

// ********* Solution *******

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // code here

        // T.c -> O(N^2)
        // S.c -> O(1)

        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
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
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
