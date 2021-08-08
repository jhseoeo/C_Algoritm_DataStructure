#include "Problems4.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmpStr(const string& a, const string& b) {
    return a + b > b + a;
}

static string solution(vector<int> numbers) {
    string answer = "";
    int n = numbers.size();

    vector<string> strnums;
    for(int i = 0; i < n; i++) 
        strnums.push_back(to_string(numbers[i]));

    sort(strnums.begin(), strnums.end(), cmpStr);

    for (int i = 0; i < n; i++)
        answer += strnums[i];

    if (answer[0] == '0') return "0";
    else return answer;
}

void solution_4_2() {
    AutomatedInput Input;
    Input.set(
        "5 "

        "3 "
        "6 10 2 "

        "5 "
        "3 30 34 5 9 "

        "6 "
        "83 8 79 92 15 19 "

        "2 "
        "40 404 "

        "9 "
        "90 908 89 898 10 101 1 8 9"
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;

        Input >> n;
        vector<int> numbers(n);
        for (size_t i = 0; i < n; i++)
            Input >> numbers[i];
        cout << solution(numbers) << endl;
    }
}