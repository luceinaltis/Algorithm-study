#include <iostream>
#include <vector>
using namespace std;

// first : score
// second : idx
vector<pair<int, int>> arr;
vector<pair<int, int>> tmp;

/*
    mergeSort
        - 분할정복 알고리즘을 이용한 정렬방법이다.
        기본적으로 O(nlogn)의 시간복잡도를 보여준다.
        퀵소트와 마찬가지로 효율이 좋은 정렬이다.
        그러나 실제로 구현해보면 퀵소트보다 안좋은 점이 몇가지 있는데
        공간복잡도가 O(2n)이라 배열을 복사하는 과정에서 오버헤드가 발생한다.
        그래서 이 점을 참고해 mergeSort를 사용해야한다. 🤔..
*/

void merge(vector<pair<int, int>> &arr, int start, int end)
{
    int l = start;
    int r = (start + end) / 2 + 1;
    int leftEnd = r - 1;

    int pos = start;

    while (l <= leftEnd && r <= end)
    {
        if (arr[l].first < arr[r].first)
        {
            tmp[pos++] = arr[l++];
        }
        else
        {
            tmp[pos++] = arr[r++];
        }
    }

    while (l <= leftEnd)
    {
        tmp[pos++] = arr[l++];
    }

    while (r <= end)
    {
        tmp[pos++] = arr[r++];
    }

    for (int i = start; i <= end; ++i)
    {
        arr[i] = tmp[i];
    }
}

void mergeSort(vector<pair<int, int>> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        // divide
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // conquer
        merge(arr, start, end);
    }
}

int main()
{
    arr.assign(8, {0, 0});
    tmp.assign(8, {0, 0});

    for (int i = 0; i < arr.size(); ++i)
    {
        cin >> arr[i].first;

        arr[i].second = i + 1;
    }

    mergeSort(arr, 0, arr.size() - 1);

    int sum = 0;
    int size = arr.size();
    vector<pair<int, int>> ansArr;
    for (int i = 0; i < 5; ++i)
    {
        sum += arr[size - 1 - i].first;
        ansArr.push_back({arr[size - 1 - i].second, arr[size - 1 - i].first});
    }

    mergeSort(ansArr, 0, ansArr.size() - 1);

    cout << sum << '\n';
    for (int i = 0; i < ansArr.size(); ++i)
    {
        cout << ansArr[i].first << ' ';
    }
    cout << '\n';

    return 0;
}