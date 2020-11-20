#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int ans = 0;

void getPartialMatch(const string &N)
{
    int m = N.size();
    int begin = 1, matched = 0;

    vector<int> pi(m, 0);
    while (begin + matched < m)
    {
        if (N[begin + matched] == N[matched])
        {
            ++matched;
            pi[begin + matched - 1] = matched;
            ans = max(ans, matched);
        }
        else
        {
            if (matched == 0)
            {
                ++begin;
            }
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}

int main()
{
    string str;

    cin >> str;

    // 문자 길이 하나하나씩 다 비교해보자
    for (int begin = 0; begin < str.size(); ++begin)
    {
        string N = str.substr(begin);
        getPartialMatch(N);
    }

    cout << ans << '\n';
    return 0;
}