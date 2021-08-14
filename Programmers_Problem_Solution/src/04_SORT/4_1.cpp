#include "Problems4.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (size_t i = 0; i < commands.size(); i++) {
        int from = commands[i][0] - 1,
            to = commands[i][1] - 1,
            idx = commands[i][2] - 1;
        vector<int> cut(array.begin() + from, array.begin() + to + 1);
        sort(cut.begin(), cut.end());
        answer.push_back(cut[idx]);
    }


    return answer;
}

void solution_4_1() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "7 "
        "1 5 2 6 3 7 4 "
        "3 "
        "2 5 3 "
        "4 4 1 "
        "1 7 3 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;

        Input >> n;
        vector<int> array(n);
        for (size_t i = 0; i < n; i++)
            Input >> array[i];

        Input >> n;
        vector<vector<int>> command(n);
        int from, to, idx;
        for (size_t i = 0; i < n; i++) {
            Input >> from >> to >> idx;
            command[i] = { from, to, idx };
        }

        vector<int> ret = solution(array, command);
        for (int v : ret) {
            cout << v << " ";
        }
        cout << endl;
    }
}