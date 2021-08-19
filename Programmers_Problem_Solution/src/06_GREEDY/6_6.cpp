#include "Problems6.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int solution(vector<vector<int>> routes) {
    int answer = 0; int n = routes.size();
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    vector<bool> crossed(n);

    for (int i = 0; i < n; i++) {
        if (crossed[i])
            continue;

        answer++;
        for (int j = i; j < n; j++) {
            if (routes[j][0] <= routes[i][1] && routes[i][1] <= routes[j][1])
                crossed[j] = true;
        }
    }
    
    return answer;
}

void solution_6_6() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "4 "
        "-20 15 "
        "-14 -5 "
        "-18 -13 "
        "-5 -3 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;

        vector<vector<int>> routes(n);
        for (size_t i = 0; i < n; i++) {
            routes[i] = vector<int>(2);
            Input >> routes[i][0] >> routes[i][1];
        }

        cout << solution(routes) << endl;
    }
}