#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1st Approach Using Hashing
// T.C -> O(N)
// S.c -> O(k)
// void printDuplicate(string str)
// {
//     unordered_map<char, int> count;
//     for (int i = 0; i < str.length(); i++)
//     {
//         count[str[i]]++;
//     }

//     for (auto val : count)
//     {
//         if (val.second > 1)
//         {
//             cout << val.first << " , Count = " << val.second <<endl;
//         }
//     }
// }

// 2nd Approach -> Using Sorting
// T.C -> O(n logn)
// S.c -> O(1)
void printDuplicate(string str)
{
    int n = str.length();
    sort(str.begin(), str.end());

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        if (count > 1)
        {
            cout << str[i] << " , Count = " << count << endl;
        }
    }
}

int main()
{
    string str = "GeeksForGeeks";
    printDuplicate(str);

    return 0;
}