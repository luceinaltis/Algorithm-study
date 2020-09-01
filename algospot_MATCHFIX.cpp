#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX_V (2+12+100)
using namespace std;

const int INF = 987654321;

int n, m;
// wins: 각 선수들의 현재 승수
// match: 각 경기들의 선수
int wins[20], match[200][2];

int V;
// 용량, 유량
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

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

			for(int next = 0; next < V; ++next)
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
	// max_element
	// wins의 배열 중 가장 큰 값을 찾아준다.
	if(*max_element(wins+1, wins+n) >= totalWins)
		return false;
	
	V = 2 + m + n;
	memset(capacity, 0, sizeof(capacity));

	for(int i = 0; i < m; ++i)
	{
		// 소스에서 각 경기로 가는 간선
		capacity[0][2+i] = 1;

		// 각 경기에서 두 선수로 가는 간선
		for(int j = 0; j < 2; ++j)
		{
			capacity[2 + i][2 + m + match[i][j]] = 1;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int maxWin = (i == 0 ? totalWins : totalWins - 1);
		// 두 선수에서 싱크(목적지)로 가는 간선
		capacity[2+m+i][1] = maxWin - wins[i];
	}

	// 조건 추가해야됨..
	// 소스에서 싱크로 경기 수 만큼 유량을 보낼 수 있고, => 첫번째
	// 실제 유량이 0번 선수에서 싱크(목적지)로가는 capacity만큼 흘렀을때 => 두번째
	// totalWins로 이긴다는 가정이므로 이 조건을 추가해야함
	return (networkFlow(0, 1) == m) && (flow[2+m][1] == (totalWins - wins[0]));
}

int main()
{
	int c;

	cin >> c;

	while(c--)
	{
		// 초기화 꼭 해주자
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		memset(wins, 0, sizeof(wins));
		memset(match, 0, sizeof(match));

		cin >> n >> m;

		// 각 선수의 현재 승수를 받자.
		for(int i = 0; i < n; ++i)
		{
			cin >> wins[i];
		}

		// 선수들이 치루는 경기들
		for(int i = 0; i < m; ++i)
		{
			cin >> match[i][0] >> match[i][1];
		}

		bool isPossible = false;
		int i;
		// 0번 선수가 이길 수 있는 승수를 탐색
		for(i = wins[0]; i <= 1000; ++i)
		{
			isPossible = canWinWith(i);

			if(isPossible) break;
		}

		if(isPossible)
		{
			cout << i << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}