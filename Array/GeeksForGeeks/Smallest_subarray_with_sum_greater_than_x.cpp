// // GFG Problem no.
// Smallest subarray with sum greater than x -> https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

// Question Description

// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

// Example 1:

// Input:
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is
// {4, 45, 6}

// Example 2:
// Input:
// A[] = {1, 10, 5, 2, 7}
//    x  = 9
// Output: 1
// Explanation:
// Minimum length subarray is {10}

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function smallestSubWithSum() which takes the array A[], its size N and an integer X as inputs and returns the required ouput.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, x ≤ 105
// 0 ≤ A[] ≤ 104

// Company tags

// Accolite Amazon Goldman Sachs Google Facebook

// ********* Solution **********

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here

        // Sliding Window

        // T.C -> O(N)
        // S.C -> O(1)

        int i = 0, j = 0;
        int sum = 0, ans = INT_MAX;
        while (j < n)
        {
            sum += arr[j];
            while (sum > x)
            {
                ans = min(ans, j - i + 1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans > n ? 0 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends