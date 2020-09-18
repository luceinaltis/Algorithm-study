#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(const string& P) {
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
vector<int> kmpSearch(const string& S, const string& P) {
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
    string S, P;

    cin >> S >> P;

    if(kmpSearch(S, P).size()) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}