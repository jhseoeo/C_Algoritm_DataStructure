#include "Problems6.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> linkedCosts;

bool findCycle(vector<bool> &link, int &from, int &pos) {
    bool res = false;
    link[pos] = true;

    for (int to : linkedCosts[pos])
        if (to == from)
            continue;
        else if (link[to])
            return true;
        else {
            res = res || findCycle(link, pos, to);
        }

    return false;
};

bool checkCycle(int n) {
    for (int i = 0; i < n; i++) {
        vector<bool> tmp(n, false);
        if (findCycle(tmp, i, i)) {
            return true;
        }
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, numLinked = 0;
    sort(costs.begin(), costs.end(), [] (const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
    linkedCosts.clear(); linkedCosts.resize(10);

    for (int i = 0; i < costs.size(); i++) {
        linkedCosts[costs[i][0]].push_back(costs[i][1]);
        linkedCosts[costs[i][1]].push_back(costs[i][0]);

        if (!checkCycle(n)) {
            answer += costs[i][2];
        } else {
            linkedCosts[costs[i][0]].erase(linkedCosts[costs[i][0]].end() - 1);
            linkedCosts[costs[i][1]].erase(linkedCosts[costs[i][1]].end() - 1);
        }

        if (numLinked == n - 1)
            break;
    }

    return answer;
}

void solution_6_5() {
    AutomatedInput Input;
    Input.set(
        "3 "

        "4 5 "
        "0 1 1 "
        "0 2 2 "
        "1 2 5 "
        "1 3 1 "
        "2 3 8 "

        "5 7 "
        "0 1 5 "
        "1 2 3 "
        "2 3 3 "
        "3 1 2 "
        "3 0 4 "
        "2 4 6 "
        "4 0 7 "

        "5 4 "
        "0 1 1 "
        "3 4 1 "
        "1 2 2 "
        "2 3 4 "

    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int n, k;
        Input >> n >> k;

        vector<vector<int>> costs;
        for (size_t i = 0; i < k; i++) {
            vector<int> elem(3);
            Input >> elem[0] >> elem[1] >> elem[2];
            costs.push_back(elem);
        }

        cout << solution(n, costs) << endl;
    }
}