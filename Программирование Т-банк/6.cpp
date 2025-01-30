#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point 
{
    int x, y;
};

bool ND(const Point& a, const Point& b, const Point& c) 
{
    return (b.y - a.y) * (c.x - a.x) != (c.y - a.y) * (b.x - a.x);
}

int main() 
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<vector<int>> hTrips;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            for (int k = j + 1; k < n; ++k) 
            {
                if (ND(points[i], points[j], points[k])) 
                {
                    hTrips.push_back({ i, j, k });
                }
            }
        }
    }

    vector<bool> used(n, false);
    int mhTrip = 0;

    for (const auto& trip : hTrips) 
    {
        if (!used[trip[0]] && !used[trip[1]] && !used[trip[2]]) 
        {
            used[trip[0]] = used[trip[1]] = used[trip[2]] = true;
            mhTrip++;
        }
    }

    cout << mhTrip << endl;
    return 0;
}
