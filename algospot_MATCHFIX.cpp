#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX_V (2+12+100)
using namespace std;

const int INF = 987654321;
int n, m;
int wins[20], match[200][2];

int V;
int capacity[2][2], flow[2][2];

// 소스에서 싱크까지의 가능한 최대유량을 반환
int networkFlow(int source, int sink)
{
	int totalFlow = 0;
	memset(flow, 0, sizeof(flow));

	// 증가경로가 있다면 계속 실행하자.
	while(true)
	{
		// 찾은 증가경로를 되돌아가면서 탐색하기 위한 배열
		vector<int> parent(MAX_V, -1);
		queue<int> que;

		// 초기화
		parent[source] = source;
		que.push(source);

		while(!que.empty())
		{
			int here = que.front(); que.pop();

			for(int next = 0; next < MAX_V; ++next)
			{
				if(capacity[here][next] - flow[here][next] > 0 && parent[next] == -1)
				{
					que.push(next);
					parent[next] = here;
				}
			}
		}

		if(parent[sink] == -1) break;

		int amount = INF;
		for(int p = sink; p != source; p = parent[p])
		{
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		}

		for(int p = sink; p != source; p = parent[p])
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}

		totalFlow += amount;
	}
	return totalFlow;
}

// 0번 선수가 totalWins로 우승할 수 있는지 여부를 반환
bool canWinWith(int totalWins)
{
	if(*max_element(wins+1, wins+n) >= totalWins)
		return false;
	
	V = 2 + m + n;
	memset(capacity, 0, sizeof(capacity));

	for(int i = 0; i < m; ++i)
	{
		capacity[0][2+i] = 1;

		for(int j = 0; j < 2; ++j)
		{
			capacity[2 + i][2 + m + match[i][j]] = 1;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int maxWin = (i == 0 ? totalWins : totalWins - 1);
		capacity[2+m+i][1] = maxWin - wins[i];
	}

	return networkFlow(0, 1) == m;
}

int main()
{
	int c;

	cin >> c;

	while(c--)
	{

		cin >> n >> m;
	}

	return 0;
}