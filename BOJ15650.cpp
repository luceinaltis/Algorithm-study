#include <iostream>
#include <vector>
using namespace std;

int n, m;

void bf(int tmpM, vector<int> &arr)
{
    // 기저사례
    if (tmpM == m)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // 탐색 부분
    int next = 1;
    if (arr.size())
    {
        next = arr.back() + 1;
    }
    for (; next <= n; ++next)
    {
        arr.push_back(next);
        bf(tmpM + 1, arr);
        arr.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> arr;

    bf(0, arr);

    return 0;
}