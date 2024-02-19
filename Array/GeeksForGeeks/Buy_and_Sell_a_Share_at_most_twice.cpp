// GFG Problem
// Buy and Sell a Share at most twice -> https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// Question Description

// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices.

// Given an array price of size n, find out the maximum profit that a share trader could have made.

// Example 1:

// Input:
// n = 6
// prices[] = {10,22,5,75,65,80}
// Output:
// 87
// Explanation:
// Trader earns 87 as sum of 12, 75 Buy at 10, sell at 22, Buy at 5 and sell at 80.
// Example 2:

// Input:
// n = 7
// prices[] = {2,30,15,10,8,25,80}
// Output:
// 100
// Explanation:
// Trader earns 100 as sum of 28 and 72 Buy at price 2, sell at 30, Buy at 8 and sell at 80,
// Your Task:

// Complete the function maxProfit() which takes an integer array price as the only argument and returns an integer, representing the maximum profit, if only two transactions are allowed.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:

// 1 <= n <= 105
// 1 <= price[i] <= 105

// Company Tags

// Amazon Facebook

// ********** Solution *********

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // User function Template for C++

    // T.C -> O(n)
    // S.C -> O(1)

    int maxProfit(vector<int> &price)
    {
        // Write your code here..
        int first_buy = INT_MIN;
        int first_sell = 0;
        int second_buy = INT_MIN;
        int second_sell = 0;

        for (int i = 0; i < price.size(); i++)
        {
            first_buy = max(first_buy, -price[i]); // we set prices to negative, so the calculation of profit will be convenient
            first_sell = max(first_sell, first_buy + price[i]);
            second_buy = max(second_buy, first_sell - price[i]); // we can buy the second only after first is sold
            second_sell = max(second_sell, second_buy + price[i]);
        }
        return second_sell;
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
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        Solution obj;
        cout << obj.maxProfit(price) << endl;
    }
}

// } Driver Code Ends