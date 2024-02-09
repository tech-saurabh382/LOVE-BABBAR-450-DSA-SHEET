// GFG Problem
// Kth smallest element - > https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Question Description

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// L=0 R=5

// Output : 7
// Explanation :
// 3rd smallest element in the given
// array is 7.
// Example 2:

// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4 L=0 R=4
// Output : 15
// Explanation :
// 4th smallest element in the given
// array is 15.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.

// Expected Time Complexity: O(n*log(n) )
// Expected Auxiliary Space: O(log(n))
// Constraints:
// 1 <= N <= 105
//  L==0
//  R==N-1
// 1<= arr[i] <= 105
// 1 <= K <= N

// Copanys Tags

// VMWare Accolite Amazon Microsoft Snapdeal Hike Adobe Google ABCO Cisco

// ****** Solution ******

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here

        // // 1st Method - Using Sorting

        // // T.C - > O(nlogn)
        // // S.C - > O(1)

        // int n = r - l + 1;
        // sort(arr, arr + n);
        // return arr[k - 1];

        // 2nd Method -> Using Max Heap (Priority Queue)

        // T.C -> O(nlogk)
        // S.C -> O(k)

        priority_queue<int> mh;
        int n = r - l + 1;

        for (int i = 0; i < k; i++)
        {
            mh.push(arr[i]);
        }

        for (int i = k; i < n; i++)
        {
            // Checking current element is smaller than top
            if (arr[i] < mh.top())
            {
                mh.pop();
                mh.push(arr[i]);
            }
        }
        return mh.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
