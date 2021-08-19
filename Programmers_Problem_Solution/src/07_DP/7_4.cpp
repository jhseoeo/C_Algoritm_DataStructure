#include "Problems7.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int cache[1000000];

static int theft(const vector<int> &money, int pos) {
    if (pos >= money.size()) return 0;
    
    int& ret = cache[pos];
    if (ret != -1) return ret;

    ret = money[pos] + max(theft(money, pos + 2),
                           theft(money, pos + 3));

    return ret;
}

static int solution(vector<int> money) {
    for (int i = 0; i < 1000000; i++) cache[i] = -1;
    int m1 = theft(money, 1);

    for (int i = 0; i < 1000000; i++) cache[i] = -1;
    int m2 = theft(money, 2);

    for (int i = 0; i < 1000000; i++) cache[i] = -1;
    money[money.size() - 1] = 0;
    int m0 = theft(money, 0);

    int answer = max(max(m0, m1), m2);

    return answer;
}

void solution_7_4() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "4 "
        "1 2 3 1 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int n;
        Input >> n;
        vector<int> money(n);

        for (int i = 0; i < n; i++)
            Input >> money[i];

        cout << solution(money) << endl;
    }
}