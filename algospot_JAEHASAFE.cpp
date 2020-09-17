
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> makeTable(const string& M)
{
    int m = M.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;

    while(begin + matched < m)
    {
        if(M[begin+matched] == M[matched])
        {
            matched++;
            pi[begin+matched-1] = matched;
        }
        else
        {
            if(matched == 0)
            {
                begin++;
            }
            else
            {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];                
            }
        }
    }
    return pi;
}



vector<int> rightKmp(const string& N, const string& M)
{
    int n = N.size(), m = M.size();
    vector<int> pi = makeTable(M);
    vector<int> ret;

    int begin = 0, matched = 0;
    while(begin + m <= n)
    {
        if(matched < m && N[begin + matched] == M[matched])
        {
            matched++;
            if(matched == m) ret.push_back(begin);
        }
        else
        {
            if(matched == 0)
            {
                begin++;
            }
            else
            {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main()
{
    int c;

    cin >> c;

    while(c--)
    {
        int n;
        int val = 0;
        cin >> n;

        vector<string> ans(n+1, "");
        
        for(int i = 0; i < n+1; ++i)
        {
            cin >> ans[i];
        }

        for(int i = 0; i < n; ++i)
        {
            if(i % 2 == 0)
            {
                // 시계방향
                val += rightKmp(ans[i+1]+ans[i+1], ans[i])[0];
            }
            else if(i % 2 == 1)
            {
                // 반시계방향
                val += rightKmp(ans[i]+ans[i], ans[i+1])[0];
            }
        }
        cout << val << '\n';
    }

    return 0;
}