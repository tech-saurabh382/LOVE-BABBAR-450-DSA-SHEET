// GFG Problem
// Count Inversions - > https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// Question Description

// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already
// sorted so there is no inversion count.
// Example 3:

// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array
// are same, so there is no inversion count.
// Your Task:

// You don't need to read input or print anything.
// Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 5*105
// 1 ≤ arr[i] ≤ 1018

// Copanys Tags

// Flipkart Amazon Microsoft MakeMyTrip Adobe BankBazaar Myntra

// ****** Solution ******

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    // T.C -> O(nlogn)
    // S.C -> O(n)

    long long merge(long long arr[], long long left, long long mid, long long right)
    {
        long long n1 = mid - left + 1;
        long long n2 = right - mid;
        long long a[n1], b[n2];
        for (long long i = 0; i < n1; i++)
        {
            a[i] = arr[left + i];
        }
        for (long long i = 0; i < n2; i++)
        {
            b[i] = arr[mid + i + 1];
        }
        long long i = 0, j = 0, k = left, count = 0;
        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                arr[k++] = a[i++];
            }
            else
            {
                arr[k++] = b[j++];
                count += (n1 - i);
            }
        }
        while (i < n1)
        {
            arr[k++] = a[i++];
        }
        while (j < n2)
        {
            arr[k++] = b[j++];
        }
        return count;
    }

    long long mergeSort(long long arr[], long long left, long long right)
    {
        long long count = 0;
        if (left >= right)
            return count;
        long long mid = (left + right) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
        return count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N - 1);
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends