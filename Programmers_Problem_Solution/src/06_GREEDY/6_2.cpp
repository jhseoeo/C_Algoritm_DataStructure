#include "Problems6.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static inline int distance(char c) {
    return c - 'A' <= 13 ? c - 'A' : 26 - (c - 'A');
}

static int move(const int& n, int mask, int curPos) {
    mask = mask | (1 << curPos);
    if (mask == (1 << n) - 1) return 0;

    int dl = 1, dr = 1;
    int posLeft = curPos == 0 ? n - 1 : curPos - 1;
    int posRight = curPos + 1;

    while (mask & (1 << posLeft)) {
        posLeft = posLeft == 0 ? n - 1 : posLeft - 1;
        dl++;
    }

    while (mask & (1 << posRight)) {
        posRight = posRight + 1;
        dr++;
    }

    if (posRight == n) return move(n, mask, posLeft) + dl;
    else return min(move(n, mask, posLeft) + dl, move(n, mask, posRight) + dr);
}

static int solution(string name) {
    int answer = 0;
    for (char c : name)
        answer += distance(c);

    int mask = 0;
    for (size_t i = 0; i < name.size(); i++)
        if (name[i] == 'A')
            mask |= 1 << i;

    return answer + move(name.size(), mask, 0);
}

void solution_6_2() {
    AutomatedInput Input;
    Input.set(
        "2 "
        "JEROEN "
        "JAN "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        string name;
        Input >> name;

        cout << solution(name) << endl;
    }
}