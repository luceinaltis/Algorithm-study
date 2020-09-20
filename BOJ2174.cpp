#include <bits/stdc++.h>
using namespace std;

// 위, 오른, 아래, 왼
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

vector<vector<int>> ground;
// first : x좌표, second : y좌표, third : 방향
vector<tuple<int, int, string>> robots;
// first : 로봇 번호, second : 명령어 종류, third : 반복 횟수
vector<tuple<int, string, int>> operations;

int A, B;
int N, M;

// 명령이 실패하면 false를 성공하면 true를 반환하자.
// 명령어 실패 에러는 이 함수에서 출력하자.
bool runOperation(int robotIndex, string operation)
{
    // 현재 로봇의 상태를 불러오자.
    int tmpX = get<0>(robots[robotIndex]);
    int tmpY = get<1>(robots[robotIndex]);
    string dir = get<2>(robots[robotIndex]);

    if(operation == "L")
    {
        string nextDir;
        if(dir == "N") nextDir = "W";
        if(dir == "E") nextDir = "N";
        if(dir == "S") nextDir = "E";
        if(dir == "W") nextDir = "S";
        
        robots[robotIndex] = make_tuple(tmpX, tmpY, nextDir);
    }
    else if(operation == "R")
    {
        string nextDir;
        if(dir == "N") nextDir = "E";
        if(dir == "E") nextDir = "S";
        if(dir == "S") nextDir = "W";
        if(dir == "W") nextDir = "N";
        
        robots[robotIndex] = make_tuple(tmpX, tmpY, nextDir);
    }
    else if(operation == "F")
    {
        int nextMove;
        if(dir == "N") nextMove = 0;
        if(dir == "E") nextMove = 1;
        if(dir == "S") nextMove = 2;
        if(dir == "W") nextMove = 3;

        int nextX = tmpX + dir_x[nextMove];
        int nextY = tmpY + dir_y[nextMove];

        // 벽에 충돌하는지 체크하자.
        if(nextX < 1 || A < nextX || nextY < 1 || B < nextY) 
        {
            cout << "Robot " << robotIndex << " crashes into the wall\n";
            return false;
        }

        // 다른 기계와 충돌하는지 체크하자.
        for(int i = 1; i <= N; ++i)
        {
            // 자기자신과는 건너뛰자.
            if(i == robotIndex) continue;
            int anotherRobotx = get<0>(robots[i]);
            int anotherRoboty = get<1>(robots[i]);

            if(anotherRobotx == nextX && anotherRoboty == nextY)
            {
                cout << "Robot " << robotIndex << " crashes into robot " << i << '\n';
                return false;
            }
        }
        // 모든 충돌 테스트를 통과했으면 결과를 저장하자.
        robots[robotIndex] = make_tuple(nextX, nextY, dir);
    }
    return true;
}

void solve()
{
    // 명령어를 실행해보자.
    for(int i = 0; i < operations.size(); ++i)
    {
        int robotIndex = get<0>(operations[i]);
        string operation = get<1>(operations[i]);
        int loopCount = get<2>(operations[i]);

        for(int j = 0; j < loopCount; ++j){
            // 명령이 실패했다면..
            if(runOperation(robotIndex, operation) == false) return;
        }
    }

    // 잘 돌아갔다면 OK를 출력하자.
    cout << "OK\n";
}

int main()
{
    cin >> A >> B;
    cin >> N >> M;

    ground.assign(A+1, vector<int>(B+1, 0));
    // 로봇의 번호는 1부터 시작한다.
    robots.assign(N+1, make_tuple(-1, -1, "A"));
    operations.assign(M, {1, "A", 1});

    // 로봇들을 저장하자.
    // 로봇의 숫자가 1부터 시작함
    for(int i = 1; i <= N; ++i)
    {
        int tmpX, tmpY;
        string tmpDir;

        cin >> tmpX >> tmpY >> tmpDir;

        robots[i] = make_tuple(tmpX, tmpY, tmpDir);
    }

    // 명령어들을 저장하자.
    for(int i = 0; i < M; ++i)
    {
        int robotIndex, loopCount;
        string oper;

        cin >> robotIndex >> oper >> loopCount;

        operations[i] = make_tuple(robotIndex, oper, loopCount);
    }

    solve();

    return 0;
}