#include "Problems4.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int solution(vector<int> citations) {
    int n = citations.size();
    vector<int> indice(n);
    for (int i = 0; i < n; i++) indice[i] = i;

    sort(citations.begin(), citations.end(), greater<int>());
    int answer = *max_element(indice.begin(), indice.end(),
            [citations](const int& a, const int& b) { return min(a + 1, citations[a]) < min(b + 1, citations[b]); });

    if (citations[0] == 0)      return 0;
    else if (citations[0] == 1) return 1;
    else                        return answer + 1;
}

void solution_4_3() {
    AutomatedInput Input;
    Input.set(
        "2 "

        "5 "
        "3 0 6 1 5 "

        "6 "
        "10 10 10 10 10 10 "

    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;

        Input >> n;
        vector<int> citations(n);
        for (size_t i = 0; i < n; i++)
            Input >> citations[i];
        cout << solution(citations) << endl;
    }
}