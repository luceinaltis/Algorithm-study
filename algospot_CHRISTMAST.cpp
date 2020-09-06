#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, k;

vector<int> arr;
vector<long long> cache;
vector<int> ret;
vector<int> prev1;

int main()
{
    cin >> t;

    while(t--)
    {
        int num1 = 0, num2 = 0;
        cin >> n >> k;

	    // 시작하는 번호를 1번으로 가정하자.		
        arr.assign(n+1, 0);
        cache.assign(k+1, 0);
        ret.assign(n+1, 0);
        prev1.assign(k+1, -1);

	    // 나머지로 바꾸어 저장하자.
        for(int i = 1; i <= n; ++i)
        {
            cin >> arr[i];

            if(i != 1) arr[i] = (arr[i] + arr[i-1])%k;

            arr[i] %= k;

            cache[arr[i]] += 1;
        }

	    // 1번 답에 대한 계산
	    // cache[나머지]에 저장된 원소들을 가지고 몇개의 조합을 만들 수 있는지 계산
        for(int i = 0; i < k; i++)
        {
		    // 나머지가 0인 경우 : 하나의 상자만 선택 할 수 있다.
            if(i == 0)
            {
                num1 += cache[i];
            }

		    // 나머지가 겹치는 상자가 2개 이상인 경우
            if(cache[i] >= 2)
            {
                num1 += ((cache[i]*(cache[i]-1))/2)%20091101;
            }

            num1 %= 20091101;
        }

	    // 2번 답에 대한 계산
	    // DP(동적계획법)
	    // 바텀-업 방식
        for(int i = 0; i <= n; ++i)
        {
            if(i > 0)
            {
                ret[i] = ret[i-1];
            }
            else
            {
                ret[i] = 0;
            }
		    // arr[i]에 담긴 나머지를 본 적이 있는지 loc에 저장
            int loc = prev1[arr[i]];

			// -1이 아니라면 arr[i]와 같은 나머지를 본 적이 있다.
			// 한 번사거나 사지 않거나 둘 중에 큰 것 반환
            if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);

			// arr[i]를 봤다는 것을 prev1에 계속 저장하자!
            prev1[arr[i]] = i;   
        }

        cout << num1 << " " << ret[n] << '\n';
    }

    
    return 0;
}