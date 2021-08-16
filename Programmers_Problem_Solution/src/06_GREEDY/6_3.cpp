#include "Problems6.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static string solution(string number, int k) {
    string answer = "";
    string copy = number; int t = k;

    while (k < number.size()) {
        int idx = max_element(number.begin(), number.begin() + k + 1) - number.begin();
        answer += number[idx];
        number.erase(number.begin(), number.begin() + idx + 1);
        k -= idx;
    }

    return answer;
}

void solution_6_3() {
    AutomatedInput Input;
    Input.set(
        "4 "
        "92942 2 "
        "1231234 2 "
        "4177252841 4 "
        "1111 2 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        string number; 
        int k;
        Input >> number >> k;

        cout << solution(number, k) << endl;
    }
}