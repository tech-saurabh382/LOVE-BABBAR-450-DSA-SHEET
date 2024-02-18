// GFG Problem no.
// Array Subset of another array-> https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

// Question Description

// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements. The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be sorted or unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

// Example 1:

// Input:
// a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
// a2[] = {11, 3, 7, 1, 7}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 2:

// Input:
// a1[] = {1, 2, 3, 4, 4, 5, 6}
// a2[] = {1, 2, 4}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 3:

// Input:
// a1[] = {10, 5, 2, 23, 19}
// a2[] = {19, 5, 3}
// Output:
// No
// Explanation:
// a2[] is not a subset of a1[]

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSubset() which takes the array a1[], a2[], its size n and m as inputs and return "Yes" if arr2 is subset of arr1 else return "No" if arr2 is not subset of arr1.

// Expected Time Complexity: O(max(n,m))
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n,m <= 105
// 1 <= a1[i], a2[j] <= 106

// // Company tags

// Accolite Qualcomm GE

// ******** Solution ********

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

// Two Pointer Approach

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (a2[j] != a1[i])
        {
            i++;
        }
        else
        {
            i++, j++;
        }
    }
    if (j == m)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}