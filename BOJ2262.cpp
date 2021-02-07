#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

list<int> arr;
list<int> arr1;

int calculate(list<int> &tmpArr)
{
    if (tmpArr.size() == 1)
        return 0;

    list<int>::iterator iter = tmpArr.begin();
    list<int>::iterator iterMax = tmpArr.begin();
    for (; iter != tmpArr.end(); ++iter)
    {
        if (*iterMax < *iter)
        {
            iterMax = iter;
        }
    }

    list<int>::iterator rightNode = iterMax;
    list<int>::iterator leftNode = iterMax;
    int diff = 98765421;
    if (++rightNode != tmpArr.end())
    {
        diff = min(diff, *iterMax - *rightNode);
    }

    if (leftNode != tmpArr.begin())
    {
        leftNode--;
        diff = min(diff, *iterMax - *leftNode);
    }

    tmpArr.erase(iterMax);

    return diff + calculate(tmpArr);
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int inp;

        cin >> inp;
        arr.push_back(inp);
    }

    arr1.resize(arr.size());
    copy(arr.begin(), arr.end(), arr1.begin());
    cout << calculate(arr1) << '\n';

    return 0;
}