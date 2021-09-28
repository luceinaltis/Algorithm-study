#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, k;

vector<vector<int>> board;
// x, y, direction, order(0~)
vector<tuple<int, int, int>> horse;
vector<vector<vector<int>>> order;

// none, right, left, up, down
int dirX[5] = {0, 0, 0, -1, 1};
int dirY[5] = {0, 1, -1, 0, 0};

void run()
{
  for (int i = 0; i < horse.size(); ++i)
  {
    int tmpX = get<0>(horse[i]);
    int tmpY = get<1>(horse[i]);
    int tmpDir = get<2>(horse[i]);

    if (order[tmpX][tmpY].size() && order[tmpX][tmpY][0] != i)
      continue;

    int nextX = tmpX + dirX[tmpDir];
    int nextY = tmpY + dirY[tmpDir];
    int color;

    if (nextX < 1 || nextX > n || nextY < 1 || nextY > n)
    {
      color = 2;
    }
    else
    {
      color = board[nextX][nextY];
    }

    switch (color)
    {
    case 0:
      // white
      for (int j = 0; j < order[tmpX][tmpY].size(); ++j)
      {
        order[nextX][nextY].push_back(order[tmpX][tmpY][j]);
      }
      order[tmpX][tmpY].clear();
      break;
    case 1:
      // red
      reverse(order[tmpX][tmpY].begin(), order[tmpX][tmpY].end());
      for (int j = 0; j < order[tmpX][tmpY].size(); ++j)
      {
        order[nextX][nextY].push_back(order[tmpX][tmpY][j]);
      }
      order[tmpX][tmpY].clear();
      break;
    case 2:
    {
      // blue
      switch (get<2>(horse[i]))
      {
      case 1:
        get<2>(horse[i]) = 2;
        break;
      case 2:
        get<2>(horse[i]) = 1;
        break;
      case 3:
        get<2>(horse[i]) = 4;
        break;
      case 4:
        get<2>(horse[i]) = 3;
        break;
      }
      nextX = tmpX + dirX[get<2>(horse[i])];
      nextY = tmpY + dirY[get<2>(horse[i])];

      int color;

      if (nextX < 1 || nextX > n || nextY < 1 || nextY > n)
      {
        color = 2;
      }
      else
      {
        color = board[nextX][nextY];
      }

      if (color == 2)
      {
        nextX = tmpX;
        nextY = tmpY;
      }
      else if (color == 1)
      {
        // red
        reverse(order[tmpX][tmpY].begin(), order[tmpX][tmpY].end());
        for (int j = 0; j < order[tmpX][tmpY].size(); ++j)
        {
          order[nextX][nextY].push_back(order[tmpX][tmpY][j]);
        }
        order[tmpX][tmpY].clear();
      }
      else if (color == 0)
      {
        // white
        for (int j = 0; j < order[tmpX][tmpY].size(); ++j)
        {
          order[nextX][nextY].push_back(order[tmpX][tmpY][j]);
        }
        order[tmpX][tmpY].clear();
      }
      break;
    }
    default:
      break;
    }

    for (int j = 0; j < horse.size(); ++j)
    {
      int &otherX = get<0>(horse[j]);
      int &otherY = get<1>(horse[j]);

      if (tmpX == otherX && tmpY == otherY)
      {
        otherX = nextX;
        otherY = nextY;
      }
    }
  }
}

int main()
{

  cin >> n >> k;

  board.assign(n + 1, vector<int>(n + 1, 0));
  order.assign(n + 1, vector<vector<int>>(n + 1, vector<int>()));
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < k; ++i)
  {
    int x, y, dir;

    cin >> x >> y >> dir;
    horse.push_back(make_tuple(x, y, dir));
    order[x][y].push_back(i);
  }

  bool isEnd = false;
  int turn = 0;
  while (!isEnd)
  {
    run();
    turn += 1;

    if (turn > 1000)
    {
      turn = -1;
      break;
    }

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (order[i][j].size() >= 4)
        {
          isEnd = true;
        }
      }
    }
  }

  cout << turn << '\n';

  return 0;
}