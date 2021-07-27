#include "Problems2.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int divide(int obj, int divisor) {
    return (obj % divisor) == 0 ? obj / divisor : obj / divisor + 1;
}

static vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, leftovers;

    for (size_t i = 0; i < progresses.size(); i++) {
        int day = divide((100 - progresses[i]), speeds[i]);
        leftovers.push_back(day);
    }

    for (size_t i = 0; i < leftovers.size(); i++) {
        cout << leftovers[i] << " ";
    } cout << endl;

    int max = leftovers[0], cnt = 1;
    for (size_t i = 1; i < leftovers.size(); i++) {
        if (max < leftovers[i]) {
            answer.push_back(cnt);
            max = leftovers[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    answer.push_back(cnt);

    return answer;
}

void solution_2_1() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "3 "
        "93 30 55 "
        "1 30 5 "
        
        "6 "
        "95 90 99 99 80 99 "
        "1 1 1 1 1 1 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;

        Input >> n;
        vector<int> progresses(n), speeds(n);

        for (size_t i = 0; i < n; i++)
            Input >> progresses[i];
        for (size_t i = 0; i < n; i++)
            Input >> speeds[i];

        vector<int> answer = solution(progresses, speeds);

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }

        cout << endl;
    }
}