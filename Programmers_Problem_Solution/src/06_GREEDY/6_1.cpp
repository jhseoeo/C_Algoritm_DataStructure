#include "Problems6.h"

#include <string>
#include <vector>

using namespace std;

static int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> availability(n, 1);
    for (const int v : lost)
        availability[v-1]--;
    for (const int v : reserve)
        availability[v-1]++;
    
    int before = 0;
    for (int i = 0; i < n; i++) {
        if (availability[i] == 0) {
            if (before == 2) {
                before = 1;
                answer++;
            } else if (i + 1 < n && availability[i + 1] == 2) {
                availability[i + 1] = 1;
                before = 1;
                answer++;
            } else {
                before = 0;
            }
        } else {
            before = availability[i];
            answer++;
        }
    }

    return answer;
}

void solution_6_1() {
    AutomatedInput Input;
    Input.set(
        "3 "
        
        "5 2 3 "
        "2 4 "
        "1 3 5 "

        "5 2 1 "
        "2 4 "
        "3 "
        
        "3 1 1 "
        "3 "
        "1 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int n, numLost, numReserve;
        Input >> n >> numLost >> numReserve;
        
        vector<int> lost(numLost), reserve(numReserve);

        for (int i = 0; i < numLost; i++)
            Input >> lost[i];

        for (int i = 0; i < numReserve; i++)
            Input >> reserve[i];

        cout << solution(n, lost, reserve) << endl;
    }
}