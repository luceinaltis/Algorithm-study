#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> room;
vector<tuple<int, int, int>> arr;

// 방 A와 방 B 거리의 절대값 차이가 큰 순(내림차순)으로 정렬하자
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
    return abs(get<1>(a) - get<2>(a)) > abs(get<1>(b) - get<2>(b));
}

int main()
{
    int n, a, b;

    while(true)
    {
        arr.clear();
        room.assign(2, 0);

        cin >> n >> a >> b;

        room[0] = a;
        room[1] = b;

        // 입력이 끝나면 종료
        if(n == 0 && a == 0 && b == 0) break;

        for(int i = 0; i < n; ++i)
        {
            // 풍선의 수, 방 A에서의 거리, 방 B에서의 거리
            int k, da, db;

            cin >> k >> da >> db;

            arr.push_back(make_tuple(k, da, db));
        }

        sort(arr. begin(), arr.end(), compare);

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int tmpK, tmpDa, tmpDb;
            // 선택할 방, 선택된 거리
            // 0 : 방 a
            // 1 : 방 b
            int selectedRoom, selectedDist;

            tmpK = get<0>(arr[i]);
            tmpDa = get<1>(arr[i]);
            tmpDb = get<2>(arr[i]);

            // 거리의 차이가 큰 것부터 처리하자.
            // 거리 차이순으로 처리하므로 방을 잘못 선택하는 경우가 없다.
            selectedRoom = (tmpDa < tmpDb ? 0 : 1);
            selectedDist = (tmpDa < tmpDb ? tmpDa : tmpDb);

            // 각 방에 남은 풍선의 수를 고려하자.
            if(room[selectedRoom] < tmpK)
            {
                // 처리해야할 풍선이 방 안의 풍선보다 많다면
                // 처리할 수 있는건 처리하자.
                ans += (room[selectedRoom] * selectedDist);

                // tmpK는 남은 풍선
                tmpK -= room[selectedRoom];
                room[selectedRoom] = 0;
                
                // 남은건 다른 방에서 처리하자.
                selectedRoom = (!selectedRoom);
                selectedDist = (selectedRoom ? tmpDb : tmpDa);
                
                room[selectedRoom] -= tmpK;
                ans += (tmpK * selectedDist);
            }
            else
            {
                // 방 안에 풍선의 양이 충분하다면
                // 방 안의 풍선을 없애고 거리를 계산하자.
                room[selectedRoom] -= tmpK;
                ans += (tmpK * selectedDist);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}