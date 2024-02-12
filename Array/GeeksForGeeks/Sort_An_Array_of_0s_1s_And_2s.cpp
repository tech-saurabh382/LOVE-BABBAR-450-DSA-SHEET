// GFG Problem
// Sort an array of 0s, 1s and 2s - > https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Question Description

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example 1:

// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.
// Example 2:

// Input:
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6
// 0 <= A[i] <= 2

// Copanys Tags

// Paytm Flipkart Morgan Stanley Amazon Microsoft OYO Rooms Samsung Snapdeal
// Hike MakeMyTrip Ola Cabs Walmart MAQ Software Adobe Yatra.com SAP LabsQualcomm

// ****** Solution ******

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        // Three Pointer Approach -> Dutch National Flag Method
        // T.C -> O(n)
        // S.C -> (1)
        int start = 0, i = 0;
        int end = n - 1;
        while (i <= end)
        {
            if (a[i] == 0)
            {
                swap(a[start], a[i]);
                start++;
                i++;
            }
            else if (a[i] == 1)
            {
                i++;
            }
            else
            {
                swap(a[i], a[end]);
                end--;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends