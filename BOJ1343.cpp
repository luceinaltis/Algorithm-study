#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

string arr;
vector<pair<char, int>> arrV;
vector<tuple<char, int, int>> answer;

void calculate()
{
    for (int i = 0; i < arrV.size(); ++i)
    {
        char ch = arrV[i].first;
        int count = arrV[i].second;

        if (ch == '.')
        {
            answer.push_back(make_tuple(ch, count, 0));
        }
        else if (ch == 'X')
        {
            int countA = -1;
            int countB = -1;

            for (int i = count / 4; i >= 0; --i)
            {
                int left = count - i * 4;
                if (left % 2 == 0)
                {
                    countA = i;
                    countB = left / 2;
                    answer.push_back(make_tuple(ch, countA, countB));
                    break;
                }
            }
        }
    }
}

int main()
{

    cin >> arr;

    int check = 0;
    char tmp = arr[0];
    for (int i = 0; i <= arr.size(); ++i)
    {
        if (i == arr.size())
        {
            arrV.push_back(make_pair(tmp, check));
            tmp = arr[i];
            check = 0;
            break;
        }

        if (tmp != arr[i])
        {
            arrV.push_back(make_pair(tmp, check));
            tmp = arr[i];
            check = 0;
        }
        check += 1;
    }

    calculate();

    if (arrV.size() != answer.size())
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            if (get<0>(answer[i]) == '.')
            {
                for (int j = 0; j < get<1>(answer[i]); ++j)
                {
                    cout << '.';
                }
            }
            else
            {
                for (int j = 0; j < get<1>(answer[i]); ++j)
                {
                    cout << "AAAA";
                }

                for (int j = 0; j < get<2>(answer[i]); ++j)
                {
                    cout << "BB";
                }
            }
        }
        cout << '\n';
    }

    return 0;
}