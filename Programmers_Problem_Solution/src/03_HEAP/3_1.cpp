#include "Problems3.h"

#include <string>
#include <vector>
#include <queue>

using namespace std;

static int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto v : scoville) pq.push(v);

    while (pq.top() < K && pq.size() >= 2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        pq.push(a + b * 2);
        answer++;
    }

    if (pq.top() < K)
        return -1;
    else
        return answer;
}

void solution_3_1() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "6 "
        "1 2 3 9 10 12 "
        "7 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        int k;

        Input >> n;
        vector<int> scoville(n);
        for (size_t i = 0; i < n; i++)
            Input >> scoville[n];

        Input >> k;
    }
}