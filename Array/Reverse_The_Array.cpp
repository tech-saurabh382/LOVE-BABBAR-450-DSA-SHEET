#include <iostream>
using namespace std;

// T.C -> O(n)
// S.C -> O(1)

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // printing an array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}