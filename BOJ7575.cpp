#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> getPartialMatch(const deque<int>& P) {
    int m = P.size();
    vector<int> pi(m, 0);

    // 왜 begin이 1부터 시작할까?
    // P에서 P를 찾는 것이기 때문에 begin이 0부터 시작하면 자기 자신을 찾는다.
    int begin = 1, matched = 0;

    while(begin + matched < m) {
        if(P[begin + matched] == P[matched]) {
            ++matched;
            // kmp 알고리즘에서
            // 이 부분만 다르다
            pi[begin+matched-1] = matched;
        } else {
            if(matched == 0) {
                begin += 1;
            }
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

// P가 S의 부분 문자열인지 확인하자.
vector<int> kmpSearch(const vector<int>& S, const deque<int>& P) {
    int n = S.size(), m = P.size();

    vector<int> ret;

    vector<int> pi = getPartialMatch(P);
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        // 만약 일치한다면
        if(matched < m && S[begin + matched] == P[matched]) {
            // 맞았다고 표시해주자
            ++matched;
            // 부분 문자 길이 m 만큼 맞았다면 일치하는 거다.
            if(matched == m) ret.push_back(begin);
        }
        else {
            // 일치하지 않거나 맞은 것이 없다면
            if(matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;
    
    vector<vector<int>> arr(n, vector<int>());

    for(int i = 0; i < n; ++i)
    {
        int m;

        cin >> m;

        arr[i].assign(m, 0);

        for(int j = 0; j < m; ++j) 
        {
            cin >> arr[i][j];
        }
    }

    // 가장 짧은 코드를 기준으로 생각하자.
    int minCodeLength = 10000;
    int index = -1;
    for(int i = 0; i < n; ++i)
    {
        if(minCodeLength > arr[i].size()) {
            minCodeLength = arr[i].size();
            index = i;
        }
    }

    bool hasVirus = false;
    
    if(k <= arr[index].size())
    {
        // 찾아야되는 부분 코드를 생성하자
        deque<int> needle(arr[index].begin(), arr[index].begin() + k);
        // 찾아야되는 부분 코드를 거꾸로 생각하자
        deque<int> needle_reverse(arr[index].begin(), arr[index].begin() + k);
        reverse(needle_reverse.begin(), needle_reverse.end());

        int begin = 0;
        while(begin + k <= arr[index].size())
        {
            if(begin != 0)
            {
                needle.push_back(arr[index][begin + k - 1]);
                needle.pop_front();

                needle_reverse.push_front(arr[index][begin + k - 1]);
                needle_reverse.pop_back();
            }

            // k 길이인 코드로 바이러스를 가지고 있나 체크하자 
            hasVirus = true;
            for(int i = 0; i < n; ++i)
            {
                // needle인 코드가 있는지 체크
                if(kmpSearch(arr[i], needle).size() == 0 && kmpSearch(arr[i], needle_reverse).size() == 0)
                {
                    hasVirus = false;
                    break;
                }
            }

            if(hasVirus) break;
            begin += 1;
        }
    }

    if(hasVirus)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n'; 
    }

    return 0;
}