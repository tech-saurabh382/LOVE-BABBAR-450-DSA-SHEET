#include <iostream>
#include <limits.h>
using namespace std;

int findMini(int arr[], int size)
{
    // inittalize the min with the maximum possible integer value
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            // found a number smaller than min, update min
            min = arr[i];
        }
    }
    return min;
}

int findMaxi(int arr[], int size)
{
    // inittalize the max with the minimum possible integer value
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            // found a number greater than max, update max
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {10, 0, -4, 13, -2, 6, 7, -8, 9, -1};
    int size = 10;

    int mini = findMini(arr, size);
    int maxi = findMaxi(arr, size);

    cout << "Minimum Element in An Array is  " << mini << endl;
    cout << "Maximum Element in An Array is  " << maxi << endl;
    return 0;
}