#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 15 + 1;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

// 무시해도 되는 문자열들을 반환하자.
int precalc()
{
    int ret = 0;
    // overlap배열을 전처리하자!
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (i == j)
                continue;
            // https://chosh95.tistory.com/33
            const string &s1 = word[i];
            const string &s2 = word[j];
            for (int len = min(s1.size(), s2.size()); len > 0; len--)
            {
                if (s1.substr(s1.size() - len) == s2.substr(0, len))
                {
                    overlap[i][j] = len;
                    break;
                }
            }

            // 쓸모없는 것 제거
            int len = s2.size();
            for (int pos = 0; pos + len <= s1.size(); ++pos)
            {
                if (s1.substr(pos, len) == s2)
                {
                    ret |= (1 << j);
                    break;
                }
            }
        }
    }

    return ret;
}

int restore(int last, int used)
{
    // 기저 사례
    if (used == (1 << k) - 1)
        return 0;

    // 메모이제아션
    int &ret = cache[last][used];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int next = 0; next < k; ++next)
    {
        // 만약 사용하지 않았다면
        if ((used & (1 << next)) == 0)
        {
            int cand = overlap[last][next] + restore(next, (used | (1 << next)));
            ret = max(ret, cand);
        }
    }
    return ret;
}

string reconsturct(int last, int used)
{
    // 기저사례
    if (used == ((1 << k) - 1))
        return "";
    // 다음에 올 문자열을 찾는다
    for (int next = 0; next < k; ++next)
    {
        if ((used & (1 << next)) == 0)
        {
            int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];

            if (ifUsed == restore(last, used))
            {
                return (word[next].substr(overlap[last][next]) + reconsturct(next, used + (1 << next)));
            }
        }
    }
    return "***oops***";
}

int main()
{
    int c;

    cin >> c;

    while (c--)
    {
        cin >> k;

        memset(cache, -1, sizeof(cache));
        memset(overlap, 0, sizeof(overlap));

        for (int i = 0; i < k; ++i)
        {
            cin >> word[i];
        }
        word[k] = "";

        int used = precalc();
        restore(k, used);

        cout << reconsturct(k, used) << '\n';
    }

    return 0;
}