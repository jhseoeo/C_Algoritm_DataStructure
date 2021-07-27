#include "Problems2.h"

#include <string>
#include <vector>

using namespace std;

static void delay(vector<int>& documents) {
    int tmp = documents[0];

    for(size_t i = 0; i < documents.size() - 1; i++) {
        documents[i] = documents[i + 1];
    }

    documents[documents.size() - 1] = tmp;
}

static int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<int> queue;
    int leftovers[10] = { 0, };
    for (size_t i = 0; i < priorities.size(); i++) {
        leftovers[priorities[i]]++;
        queue.push_back(i);
    }

    int maxIdx = 9, position = 101;

    do {
        while (leftovers[maxIdx] == 0) {
            maxIdx--;
        }

        if (priorities[queue[0]] == maxIdx) {
            position = queue[0];
            queue.erase(queue.begin());
            leftovers[maxIdx]--;
            answer++;
        } else {
            delay(queue);
        }
    } while (position != location);

    return answer;
}

void solution_2_2() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "4 "
        "2 1 3 2  "
        "2 "

        "6 "
        "1 1 9 1 1 1 "
        "0 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;

        vector<int> priorities(n);
        int location;
        
        for (size_t i = 0; i < priorities.size(); i++)
            Input >> priorities[i];
        
        Input >> location;

        cout << solution(priorities, location) << endl;
    }
}