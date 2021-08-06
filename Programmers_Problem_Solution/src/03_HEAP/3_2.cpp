#include "Problems3.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    int answer = 0;

    int process = 0;
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    while (jobs.size() > 0) {
        size_t i; bool found = false;
        for (i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= process) {
                found = true;
                break;
            }
        }
        if(found) {
            process += jobs[i][1];
            answer += process - jobs[i][0];
            jobs.erase(jobs.begin() + i);
        } else {
            auto k = min_element(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
            process = (*k)[0] + (*k)[1];
            answer += (*k)[1];
            jobs.erase(k);
        }
    }

    return answer / size;
}

void solution_3_2() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "3 "
        "0 3 "
        "1 9 "
        "2 6 "

        "4 "
        "0 3 "
        "1 9 "
        "2 6 "
        "24 3"
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;

        vector<vector<int>> jobs(n);
        for (size_t i = 0; i < n; i++) jobs[i].resize(2);

        for (size_t i = 0; i < n; i++) {
            Input >> jobs[i][0];
            Input >> jobs[i][1];
        }

        std::cout << solution(jobs) << endl;
    }
}