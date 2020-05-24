#include <iostream>
#include <vector>
#include <algorithm>
#define MAXVALUE 100
#define MINVALUE 0
using namespace std;

typedef pair<double, double> P;


// return convex hull's min value when x is given.
double evaluate_min(const vector<P>& polygon, double x)
{
    double ret = MAXVALUE;
    for(int i = 0; i + 1 < polygon.size(); i++)
    {
        if((polygon[i].first <= x && x <= polygon[i+1].first) || (polygon[i].first >= x && x >= polygon[i+1].first))
        {
            P a1 = polygon[i], a2 = polygon[i+1];

            // 기울기
            double slope = (a1.second - a2.second)/(a1.first - a2.first);

            // 함수값
            ret = min(ret, slope*(x - a1.first) + a1.second);
        }
    }

    // 마지막 선분
    int last = polygon.size() - 1;
    if((polygon[last].first <= x && x <= polygon[0].first) || (polygon[last].first >= x && x >= polygon[0].first))
    {
        P a1 = polygon[last], a2 = polygon[0];

        // 기울기
        double slope = (a1.second - a2.second)/(a1.first - a2.first);

        // 함수값
        ret = min(ret, slope*(x - a1.first) + a1.second);
    }
    return ret;
}

// return convex hull's max value when x is given.
double evaluate_max(const vector<P>& polygon, double x)
{
    double ret = MINVALUE;
    for(int i = 0; i + 1 < polygon.size(); i++)
    {
        if((polygon[i].first <= x && x <= polygon[i+1].first) || (polygon[i].first >= x && x >= polygon[i+1].first))
        {
            P a1 = polygon[i], a2 = polygon[i+1];

            // 기울기
            double slope = (a1.second - a2.second)/(a1.first - a2.first);

            // 함수값
            ret = max(ret, slope*(x - a1.first) + a1.second);
        }
    }

    // 마지막 선분
    int last = polygon.size() - 1;
    if((polygon[last].first <= x && x <= polygon[0].first) || (polygon[last].first >= x && x >= polygon[0].first))
    {
        P a1 = polygon[last], a2 = polygon[0];

        // 기울기
        double slope = (a1.second - a2.second)/(a1.first - a2.first);

        // 함수값
        ret = max(ret, slope*(x - a1.first) + a1.second);
    }
    return ret;
}

// 주어진 x좌표의 겹치는 폭 계산
double function(const vector<P>& polygonA, const vector<P>& polygonB, double x)
{
    double a_min = evaluate_min(polygonA, x);
    double a_max = evaluate_max(polygonA, x);
    double b_min = evaluate_min(polygonB, x);
    double b_max = evaluate_max(polygonB, x);

    double ret = 0;

    double minimum = max(a_min, b_min);

    if(a_max <= b_max)
    {
        ret = a_max - minimum;
    }
    else
    {
        ret = b_max - minimum;
    }
    
    if(ret < 0) ret = 0;


    return ret;
}

double solve(const vector<P>& polygonA, const vector<P>& polygonB)
{
    double lo, hi;
    double lo1 = MAXVALUE, hi1 = MINVALUE;
    double lo2 = MAXVALUE, hi2 = MINVALUE;

    for(int i = 0; i < polygonA.size(); i++)
    {
        lo1 = min(lo1, polygonA[i].first);
        hi1 = max(hi1, polygonA[i].first);
    }

    for(int i = 0; i < polygonB.size(); i++)
    {
        lo2 = min(lo2, polygonB[i].first);
        hi2 = max(hi2, polygonB[i].first);
    }

    lo = max(lo1, lo2);
    hi = min(hi1, hi2);

    int iter = 101;
    while (iter--)
    {
        double x1 = (2*lo + hi)/3;
        double x2 = (lo + 2*hi)/3;

        double y1 = function(polygonA, polygonB, x1);
        double y2 = function(polygonA, polygonB, x2);

        if(y1 >= y2)
        {
            hi = x2;
        }
        else
        {
            lo = x1;
        }
    }
    
    return lo;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int C;

    cin >> C;

    while(C--)
    {
        int n, m;
        double ans_x;
        vector<P> polygonA;
        vector<P> polygonB;

        cin >> n >> m;

        polygonA.assign(n, P(0, 0));
        polygonB.assign(m, P(0, 0));

        // polygonA insertion
        for(int i = 0; i < n; i++)
        {
            cin >> polygonA[i].first >> polygonA[i].second;
        }

        // polygonB insertion
        for(int i = 0; i < m; i++)
        {
            cin >> polygonB[i].first >> polygonB[i].second;
        }

        ans_x = solve(polygonA, polygonB);

        cout << fixed;
        cout.precision(10);
        cout << function(polygonA, polygonB, ans_x) << '\n';
    }

    return 0;
}