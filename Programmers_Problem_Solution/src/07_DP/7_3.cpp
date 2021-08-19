#include "Problems7.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX = 1000000007;
static int cache[100][100];

static bool onPuddle(const vector<vector<int>>& puddles, const int& x, const int& y) {
    for (size_t i = 0; i < puddles.size(); i++) {
        cout << x << " " << y << " " << puddles[i][0] << " "  << puddles[i][1] << endl;
        if (puddles[i][0] == x && puddles[i][1] == y)
            return true;
    }
    return false;
}

static int findWay(const int& m, const int& n, const vector<vector<int>>& puddles,
            int x, int y) {

    if (x >= m || y >= n)               return 0;
    else if (onPuddle(puddles, x, y))   return 0;
    else if (x == m - 1 && y == n - 1)  return 1;

    int& ret = cache[x][y];
    if (ret != -1) return ret;

    ret = (findWay(m, n, puddles, x + 1, y) + findWay(m, n, puddles, x, y + 1)) % MAX;
        
    return ret;
}

static int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cache[i][j] = -1;

    return findWay(m, n, puddles, 0, 0);
}

void solution_7_3() {
    AutomatedInput Input;
    Input.set(
        "3 "

        "4 4 2 "
        "3 2 "
        "2 4 "

        "7 4 9 "
        "2 1 "
        "2 2 "
        "2 3 "
        "4 2 "
        "4 3 "
        "4 4 "
        "4 4 "
        "6 2 "
        "6 3 "

        "100 100 0 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int m, n, l;
        Input >> m >> n >> l;
        
        vector<vector<int>> puddles;
        for (int i = 0; i < l; i++) {
            int x, y;
            Input >> x >> y;
            puddles.push_back({ x - 1, y - 1 });
        }
        
        cout << solution(m, n, puddles) << endl;
    }
}