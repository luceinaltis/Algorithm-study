#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> arr;

/*
    삽입정렬
        - 버블정렬과 선택정렬과 같이 시간복잡도가 O(n^2)이다.
        한 요소가 삽입되어야할 장소를 계속 찾아나가는 것이 포인트인듯
*/

void insertionSort(vector<int> &arr, bool isAsc = true)
{
    int size = arr.size();
    for (int i = 0; i < size; ++i)
    {
        int tmpValue = arr[i];
        for (int j = i; j >= 0; --j)
        {
            if (j == 0 || arr[j - 1] < tmpValue)
            {
                arr[j] = tmpValue;
                break;
            }
            arr[j] = arr[j - 1];
        }
    }
}

int main()
{
    int n;

    cin >> n;

    set<int> st;

    for (int i = 0; i < n; ++i)
    {
        int inp;

        cin >> inp;

        st.insert(inp);
    }

    set<int>::reverse_iterator iter;
    for (iter = st.rbegin(); iter != st.rend(); iter++)
    {
        arr.push_back(*iter);
    }

    insertionSort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}