// GFG Problem no.
// Triplet Sum in Array -> https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Question Description

// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in
// the array sums up to 13.
// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in
// the array sums up to 10.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 103
// 1 ≤ A[i] ≤ 105

// Company tags

// Accolite Amazon Microsoft OYO Rooms Samsung CarWale

// ******** Solution ********

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here

        // Two Pointer Approach
        // T.C -> O(N^2)
        // S.C -> O(1)

        sort(A, A + n);
        for (int i = 0; i < n; i++)
        {
            int remSum = X - A[i];
            int start = i + 1, end = n - 1;
            while (start < end)
            {
                if (A[start] + A[end] == remSum)
                {
                    return true;
                }
                else if (A[start] + A[end] > remSum)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends