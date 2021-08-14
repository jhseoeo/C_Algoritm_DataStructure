#include "Problems5.h"

#include <string>
#include <vector>
#include <cmath>

using namespace std;

static vector<int> solution(int brown, int yellow) {
    int b = -(brown / 2 + 2);
    int c = brown + yellow;

    int val = b * b - 4 * c;
    int x1 = (-b + sqrt(val)) / 2;
    int x2 = (-b - sqrt(val)) / 2;
        
    return {x1, x2};
}

void solution_5_3() {
    AutomatedInput Input;
    Input.set(
        "3 "
        "10 2 "
        "8 1 "
        "24 24 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int brown, yellow;
        Input >> brown >> yellow;

        vector<int> result = solution(brown, yellow);
        for (size_t i = 0; i < result.size(); i++)
            cout << result[i] << " ";

        cout << endl;
    }
}