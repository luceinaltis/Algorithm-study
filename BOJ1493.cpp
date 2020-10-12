#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// index : 큐브 크기, value : 남은 큐브 갯수
vector<pair<int, int>> cubeArr;

bool answer = true;
int countAnswer = 0;

// length, width, height의 공간에 가능한 큐브를 넣고 남은 공간을 쪼개자!
void divide(const int length, const int width, const int height) 
{
    if(answer == false) return;
    if(length == 0 || width == 0 || height == 0) return;

    for(int i = 0; i < cubeArr.size(); i++){
        pair<int, int> cube = cubeArr[i];

        int cubeLength = cube.first;
        int cubeCount = cube.second;

        // 가장 큰 큐브의 종류를 넣자.
        if(cubeLength <= length && cubeLength <= width && cubeLength <= height && cubeCount > 0) 
        {
            cubeArr[i].second -= 1;
            countAnswer += 1;

            // 남은 공간을 3개의 공간으로 나누자.
            divide(length, width, height - cubeLength);
            divide(cubeLength, width - cubeLength, cubeLength);
            divide(length - cubeLength, width, cubeLength);
            // 나누었으면 종료시키자.
            return;
        }
    }

    answer = false;
}

int main()
{
    int length, width, height;
    int n;

    cin >> length >> width >> height;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {  
        int a, b;
        cin >> a >> b;

        cubeArr.push_back({pow(2, a), b});
    }

    // 내림차순 정렬
    sort(cubeArr.begin(), cubeArr.end(), greater<pair<int, int>>());

    divide(length, width, height);

    if(answer) {
        cout << countAnswer << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}