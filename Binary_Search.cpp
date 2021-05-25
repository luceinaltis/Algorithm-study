#include <iostream>
#include <vector>

using namespace std;
vector<int> sortedArr;

void printArr(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int lower_bound(const vector<int> &arr, int val)
{
    int l = 0, r = arr.size() - 1;

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < val)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int upper_bound(const vector<int> &arr, int val)
{
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] <= val)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    sortedArr.push_back(1);
    sortedArr.push_back(1);
    sortedArr.push_back(3);
    sortedArr.push_back(4);
    sortedArr.push_back(6);
    sortedArr.push_back(6);
    sortedArr.push_back(10);
    sortedArr.push_back(13);

    printArr(sortedArr);

    cout << upper_bound(sortedArr, 1) << '\n';
    cout << upper_bound(sortedArr, 2) << '\n';
    cout << upper_bound(sortedArr, 3) << '\n';
    cout << upper_bound(sortedArr, 4) << '\n';
    cout << upper_bound(sortedArr, 5) << '\n';
    cout << upper_bound(sortedArr, 6) << '\n';
    cout << upper_bound(sortedArr, 7) << '\n';
}