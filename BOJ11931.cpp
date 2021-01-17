#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void swap(vector<int> &arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    swap(arr, mid, start);

    int pivotIdx = start;

    int leftPos = start;
    int rightPos = end;

    while (leftPos < rightPos)
    {
        while (arr[pivotIdx] > arr[rightPos])
        {
            rightPos--;
        }

        while (leftPos < rightPos && arr[pivotIdx] <= arr[leftPos])
        {
            leftPos++;
        }

        swap(arr, leftPos, rightPos);
    }

    swap(arr, pivotIdx, leftPos);

    return leftPos;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    arr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}