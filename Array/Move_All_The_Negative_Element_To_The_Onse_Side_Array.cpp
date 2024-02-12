#include <iostream>
using namespace std;

// T.C - > O(n)
// S.C - > O(1)

void moveAllNegToLeft(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (arr[start] < 0)
        {
            start++;
        }
        else if (arr[end] >= 0)
        {
            end--;
        }
        else
        {
            swap(arr[start], arr[end]);
        }
    }
}

int main()
{
    int arr[] = {7, -1, 0, -3, 2, -6, -2, 8, 11, -2, 13, 14};
    int n = 12;

    moveAllNegToLeft(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}