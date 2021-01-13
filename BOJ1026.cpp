#include <iostream>
#include <vector>
using namespace std;

/*
    선택 정렬
        - 시간복잡도 O(n^2)이 나온다.
        배열을 순회하면서 요소들이 있어야 될 곳을 찾아주는 정렬법
        만들기는 간단하지만 다른 좋은 정렬들이 많기 때문에 굳이 쓸 필요는 없을듯..?
*/

vector<int> arr_A, arr_B;

void swap(vector<int> &arr, int aIdx, int bIdx)
{
    int temp = arr[aIdx];
    arr[aIdx] = arr[bIdx];
    arr[bIdx] = temp;
}

void selectionSort(vector<int> &arr, bool isAsc = true)
{
    int size = arr.size();
    if (isAsc)
    {
        for (int i = 0; i < size; ++i)
        {
            int minIdx = i;
            for (int j = i; j < size; ++j)
            {
                if (arr[minIdx] > arr[j])
                {
                    minIdx = j;
                }
            }

            swap(arr, i, minIdx);
        }
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            int maxIdx = i;
            for (int j = i; j < size; ++j)
            {
                if (arr[maxIdx] < arr[j])
                {
                    maxIdx = j;
                }
            }

            swap(arr, i, maxIdx);
        }
    }
}

int main()
{
    int n;
    int ans = 0;

    cin >> n;

    arr_A.assign(n, 0);
    arr_B.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr_A[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> arr_B[i];
    }

    selectionSort(arr_A, true);
    selectionSort(arr_B, false);

    for (int i = 0; i < n; ++i)
    {
        ans += arr_A[i] * arr_B[i];
    }

    cout << ans << '\n';

    return 0;
}