#include "Problems.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// returns comp starts with str
static bool startswith(const string &str, const string& comp) {
    if (str.size() > comp.size()) return false;

    for (size_t i = 0; i < str.size(); i++)
        if (comp[i] != str[i]) return false;
    
    return true;
}

static bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (size_t cur = 0; cur < phone_book.size() - 1; cur++) {
        if (startswith(phone_book[cur], phone_book[cur + 1])) {
            answer = false;
            break;
        }
    }

    return answer;
}

void solution_1_2() {
    AutomatedInput Input;
    Input.set(
        "3 "
        "3 119 97674223 1195524421 "
        "3 123 456 789 "
        "5 12 123 1235 568"
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        vector<string> phone_book;
        int n;
        string tmp;

        Input >> n;
        for (int i = 0; i < n; i++) {
            Input >> tmp;
            phone_book.push_back(tmp);
        }

        cout << solution(phone_book) << endl;
    }
}