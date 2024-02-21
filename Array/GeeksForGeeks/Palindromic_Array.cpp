// GFG Problem no.
// Palindromic Array -> https://www.geeksforgeeks.org/problems/palindromic-array-1587115620/1

// Question Description

// Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

// Example 1:

// Input:
// 5
// 111 222 333 444 555

// Output:
// 1

// Explanation:
// A[0] = 111 //which is a palindrome number.
// A[1] = 222 //which is a palindrome number.
// A[2] = 333 //which is a palindrome number.
// A[3] = 444 //which is a palindrome number.
// A[4] = 555 //which is a palindrome number.
// As all numbers are palindrome so This will return 1.
// Example 2:

// Input:
// 3
// 121 131 20

// Output:
// 0

// Explanation:
// 20 is not a palindrome hence the output is 0.

// Constraints:
// 1 <=T<= 50
// 1 <=n<= 20
// 1 <=A[]<= 105

// ********* Solution *******

//{ Driver Code Starts
#include <iostream>
#include <string.h>
using namespace std;

// } Driver Code Ends
/*Complete the function below*/

class Solution
{
public:
    bool isPalindrom(int a)
    {
        string s = to_string(a);
        int start = 0, end = s.size() - 1;

        bool flag = true;

        while (start < end)
        {
            if (s[start] != s[end])
            {
                flag = false;
                break;
            }
            start++, end--;
        }
        return flag;
    }

    int PalinArray(int a[], int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            if (!isPalindrom(a[i]))
            {
                return 0;
            }
        }
        return 1;
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
            cin >> a[i];
        Solution obj;
        cout << obj.PalinArray(a, n) << endl;
    }
}
// } Driver Code Ends