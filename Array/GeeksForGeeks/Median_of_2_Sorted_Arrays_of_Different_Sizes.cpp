// GFG Problem no.
// Median of 2 Sorted Arrays of Different Sizes -> https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// Question Description

// Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

// Example 1:

// Input:
// m = 3, n = 4
// array1[] = {1,5,9}
// array2[] = {2,3,6,7}
// Output: 5
// Explanation: The middle element for
// {1,2,3,5,6,7,9} is 5
// Example 2:

// Input:
// m = 2, n = 4
// array1[] = {4,6}
// array2[] = {1,2,3,5}
// Output: 3.5
// Your Task:
// The task is to complete the function MedianOfArrays() that takes array1 and array2 as input and returns their median.

// Can you solve the problem in expected time complexity?

// Expected Time Complexity: O(min(log n, log m)).
// Expected Auxiliary Space: O((n+m)/2).

// Constraints:
// 0 ≤ m,n ≤ 106
// 1 ≤ array1[i], array2[i] ≤ 109

// Company Tags

// Amazon Microsoft Samsung Google

// ********* Solution **********

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        
        // T.C -> O(min(log n, log m))
        // S.C -> O((n+m)/2).
        
        int n1 = array1.size();
        int n2 = array2.size();
        if(n1 > n2) return MedianOfArrays(array2,array1);
        int low = 0, high = n1;
        int left = (n1+n2+1) / 2;
        int n = n1+n2;
        while(low <= high){
            int mid1 = (low+high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = array1[mid1];
            if(mid2 < n2) r2 = array2[mid2];
            if(mid1 - 1 >= 0) l1 = array1[mid1-1];
            if(mid2 - 1 >= 0) l2 = array2[mid2-1];
            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1) return max(l1,l2);
                return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends