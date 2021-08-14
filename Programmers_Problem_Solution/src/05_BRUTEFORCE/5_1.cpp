#include "Problems5.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int SECOND[] = { 1, 3, 4, 5 };
static int THIRD[] = { 3, 1, 2, 4, 5 };

static vector<int> solution(vector<int> answers) {
    vector<int> answer;
    size_t n = answers.size();
    
    int st = 0, nd = 0, rd = 0;
    for (size_t i = 0; i < n; i++) {
        if (answers[i] == (i % 5) + 1)
            st++;
    }

    for (size_t i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if (answers[i] == 2)
                nd++;
        } else {
            if (answers[i] == SECOND[(i / 2) % 4])
                nd++;
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (answers[i] == THIRD[(i / 2) % 5])
            rd++;
    }

    int maximum = max(max(st, nd), rd);
    if (st == maximum) answer.push_back(1);
    if (nd == maximum) answer.push_back(2);
    if (rd == maximum) answer.push_back(3);

    return answer;
}

void solution_5_1() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "5 "
        "1 2 3 4 5 "
        
        "5 "
        "1 3 2 4 2 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;

        vector<int> answers(n);
        for (size_t i = 0; i < n; i++)
            Input >> answers[i];

        vector<int> result = solution(answers);
        for (size_t i = 0; i < result.size(); i++)
            cout << result[i] << " ";

        cout << endl;
    }
}