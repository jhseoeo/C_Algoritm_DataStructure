#include "Problems2.h"

#include <string>
#include <vector>
#include <set>

using namespace std;

int getMaxAppr(const set<int>& exists, int n) {
    int ret = -1;
    for (const int iter : exists)
        if (iter < n)   ret = iter;
        else            break;

    return ret;
}

vector<int> solution(vector<int> prices) {
    size_t size = prices.size();
    vector<int> answer(size), idxLoc(10000);
    set<int> exists;
    for (int& iter : idxLoc) iter = size - 1;

    for (int i = prices.size() - 1; i >= 0; i--) {
        //int appr = getMaxAppr(exists, prices[i]);
        auto appr = exists.lower_bound(prices[i]);

        if (appr != exists.begin()) {
            answer[i] = idxLoc[*(--appr)] - i;
        } else {
            answer[i] = size - i - 1;
        }
        exists.insert(prices[i]);

        for (int j = prices[i]; j < 10000; j++) idxLoc[j] = i;
    }

    return answer;
}

void solution_2_4() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "5 "
        "1 2 3 2 3 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int n;
        Input >> n;
        vector<int> prices(n);
        
        for (int i = 0; i < n; i++)
            Input >> prices[i];

        vector<int> answer = solution(prices);

        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
}