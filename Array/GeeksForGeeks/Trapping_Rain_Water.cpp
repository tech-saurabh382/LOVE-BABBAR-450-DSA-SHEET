// GFG Problem no.
// Trapping Rain Water -> https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Question Description

// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation:

// Example 2:

// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above
// block of height 4 is 3 units and above
// block of height 0 is 7 units. So, the
// total unit of water trapped is 10 units.
// Example 3:

// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Your Task:
// You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 3 < N < 106
// 0 < Ai < 108

// Company tags

// Flipkart Amazon Microsoft Google

// ******** Solution ********

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    // Two Pointer Approach
    // T.C -> O(N)
    // S.C -> O(1)

    long long trappingWater(int arr[], int n)
    {
        // code here
        int left = 0;
        int right = n - 1;
        int leftbar = arr[0];
        int rightbar = arr[n - 1];

        long long ans = 0;

        while (left <= right)
        {
            // which bar is limiting
            // left, right ?
            if (leftbar < rightbar)
            {
                // if the element that you are seeing,
                // now if that become the highest left ,
                // it will not store any water
                if (arr[left] > leftbar)
                {
                    leftbar = arr[left];
                }
                else
                {
                    // it will store water
                    ans += leftbar - arr[left];
                    left++;
                }
            }
            else
            {
                if (arr[right] > rightbar)
                {
                    rightbar = arr[right];
                }
                else
                {
                    ans += rightbar - arr[right];
                    right--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends