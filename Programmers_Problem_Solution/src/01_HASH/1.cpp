#include "Problems.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

static string solution(vector<string> participant, vector<string> completion) {
    map<string, int> dict;

    for (size_t i = 0; i < participant.size(); i++) {
        if (dict.find(participant[i]) == dict.end())
            dict.insert({ participant[i], 1 });
        else
            dict[participant[i]]++;
    }

    for (size_t i = 0; i < completion.size(); i++)
        dict[completion[i]]--;

    string answer = "";
    for (const auto iter : dict) {
        if (iter.second != 0) {
            answer = iter.first;
            break;
        }
    }

    return answer;
}

void solution_1_1() {
    AutomatedInput Input;
    Input.set(
        "3 "
        "3 leo kiki eden "
        "2 eden kiki "

        "5 marina josipa nikola vinko filipa "
        "4 josipa filipa marina nikola "

        "4 mislav stanko mislav ana "
        "3 stanko ana mislav "
    );
       
    int T;
    Input >> T;

    for(int trial = 0; trial < T; trial++) {
        vector<string> participant, completion;
        int n;
        string tmp;

        Input >> n;
        for (int i = 0; i < n; i++) {
            Input >> tmp;
            participant.push_back(tmp);
        }

        Input >> n;
        for (int i = 0; i < n; i++) {
            Input >> tmp;
            completion.push_back(tmp);
        }

        cout << solution(participant, completion) << endl;
    }
}