#include "Problems6.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    size_t front = 0, rear = people.size() - 1;

    while (front < rear) {
        if (people[front] + people[rear] > limit) {
            rear--;
            answer++;
        } else {
            front++;
            rear--;
            answer++;
        }
    }

    if (front == rear) answer++;

    return answer;
}

void solution_6_4() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "4 100 "
        "70 50 80 50 "
        
        "3 100 "
        "70 80 50 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n; int limit;
        Input >> n >> limit;

        vector<int> people(n);
        for (size_t i = 0; i < n; i++)
            Input >> people[i];

        cout << solution(people, limit) << endl;
    }
}