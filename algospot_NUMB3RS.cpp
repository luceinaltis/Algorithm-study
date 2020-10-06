#include <iostream>
#include <cstring>
using namespace std;

int adj[50][50];
// n : 마을의 수
// d : 지난 날짜
// p : 교도소가 있는 마을 번호
int n, d, p;
int t;

// first : d일이 지났다
// second : 마을의 번호(0 ~ n-1)
// d일이 지난 마을에 범인이 있을 확률
double cache[101][50];
// 현재 마을에 연결되어있는 도로의 개수를 미리 저장해놓자!
int roadSize[50];

// days일이 지난 town에 범인이 있을 확률을 반환해주자!
// 점화식
// dp(days, town) = (dp(days-1, 연결된 마을) / 연결된 마을의 도로 수)를 전부 더하자!
double dp(int days, int town)
{
    // 기저사례
    // 첫 날의 확률을 미리 cache에 저장해놓자.
    // 첫 날에서 메모이제이션을 통해 값을 반환하므로 기저사례 처리 안해도 됨.

    // 메모이제이션
    double& ret = cache[days][town];
    if(ret != -1.0) return ret;

    // 점화식 
    ret = 0.0;
    for(int nextTown = 0; nextTown < n; ++nextTown)
    {
        // 연결되어있다면
        if(adj[town][nextTown] == 1)
        {
            ret += dp(days - 1, nextTown) / double(roadSize[nextTown]);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << fixed;
    cout.precision(8);

    int c;

    cin >> c;

    while(c--)
    {
        for(int i = 0; i < 101; ++i)
        {
            for(int j = 0; j < 50; ++j)
            {
                cache[i][j] = -1.0;
            }
        }

        memset(adj, 0, sizeof(adj));
        memset(roadSize, 0,  sizeof(roadSize));

        // 마을의 순서 : 0 ~ n-1
        cin >> n >> d >> p;

        // 마을의 연결 여부를 입력받자!
        for(int i = 0; i < n; ++i)
        {
            int tmpRoadSize = 0;
            for(int j = 0; j < n; ++j) 
            {
                cin >> adj[i][j];
                if(adj[i][j] == 1)
                {
                    tmpRoadSize += 1;
                }
            }
            roadSize[i] = tmpRoadSize;
        }

        // 마을의 첫날에 범인이 있을 확률을 전처리해주자.
        for(int i = 0; i < 50; ++i)
        {
            // 교도소와 연결되어 있을 경우
            if(adj[p][i] == 1)
            {
                cache[1][i] = 1.0 / double(roadSize[p]);
            }
            else
            {
                // 교도소와 연결되어 있지 않을 경우
                cache[1][i] = 0.0;
            }
        }

        cin >> t;

        for(int i = 0; i < t; ++i)
        {
            int tmpTown;

            cin >> tmpTown;

            cout << dp(d, tmpTown) << ' ';
        }
        cout << '\n';
    }

    return 0;
}