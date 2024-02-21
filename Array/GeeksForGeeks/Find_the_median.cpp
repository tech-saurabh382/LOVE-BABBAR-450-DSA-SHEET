// GFG Problem no.
// Find the median -> https://www.geeksforgeeks.org/problems/find-the-median0527/1

// Question Description

// Given an array arr[] of N integers, calculate the median.

// NOTE: Return the floor value of the median.

// Example 1:

// Input: N = 5
// arr[] = 90 100 78 89 67
// Output: 89
// Explanation: After sorting the array
// middle element is the median

// Example 2:

// Input: N = 4
// arr[] = 56 67 30 79
// Output: 61
// Explanation: In case of even number of
// elements, average of two middle elements
// is the median.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function find_median() which takes the array as input parameter and return the floor value of the median.

// Expected Time Complexity: O(n * log(n))
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= Length of Array <= 100
// 1 <= Elements of Array <= 100

// Company Tags

// Accolite Amazon Samsung FactSet

// ********* Solution *********

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
public:
    int find_median(vector<int> v)
    {
        // Code here.

        // T.c -> O(nlogn);
        //  S.c -> O(1)

        int ans;
        int size = v.size();

        sort(v.begin(), v.end());

        if (size % 2 == 0)
        {
            ans = (v[size / 2 - 1] + v[size / 2]) / 2;
        }
        else
        {
            ans = v[size / 2];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends