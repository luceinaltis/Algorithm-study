#include <iostream>
#include <vector>
using namespace std;

/*
    퀵 소트
        - logn만큼 쪼개지고, 쪼개진 각각 n만큼의 시간이 든다..
        partition 함수를 새롭게 짜봤는데 상당히 간단하다.
        앞으로 퀵소트를 짤 때 이 방식을 쓰면 상당히 좋을듯
*/

void swap(vector<int> &arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];

    int i = start + 1;
    for (int j = start + 1; j <= end; ++j)
    {
        if (arr[j] <= pivot)
        {
            swap(arr, j, i);
            i += 1;
        }
    }

    swap(arr, start, i - 1);

    return i - 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotIdx = partition(arr, start, end);

        quickSort(arr, start, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> arr;

    cin >> n;

    arr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}