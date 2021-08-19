#include "Problems7.h"

#include <string>
#include <vector>

using namespace std;

static int cache[500][500];

static int findway(const vector<vector<int>>& triangle, int y, int x) {
    if (y >= triangle.size())
        return 0;

    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    ret = triangle[y][x] + max(findway(triangle, y + 1, x),
                               findway(triangle, y + 1, x + 1));
    
    return ret;
}

static int solution(vector<vector<int>> triangle) {
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            cache[i][j] = -1;

    return findway(triangle, 0, 0);
}

void solution_7_2() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "5 "
        "7 "
        "3 8 "
        "8 1 0 "
        "2 7 4 4 "
        "4 5 2 6 5 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;
        vector<vector<int>> triangle(n);
        
        for (size_t i = 0; i < n; i++) {
            triangle[i].resize(i+1);

            for (size_t j = 0; j <= i; j++) {
                Input >> triangle[i][j];
            }
        }

        cout << solution(triangle) << endl;
    }
}