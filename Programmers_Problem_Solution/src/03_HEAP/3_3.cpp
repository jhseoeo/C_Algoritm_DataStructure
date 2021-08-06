#include "Problems3.h"

#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

static vector<int> solution(vector<string> operations) {
    set<int> res;

    for (size_t i = 0; i < operations.size(); i++) {
        stringstream s(operations[i]);
        string oper, val;
        s >> oper >> val;

        switch (oper[0]) {
        case 'I':
            res.insert(stoi(val));
            break;

        case 'D':
            if (res.size() == 0) break;
            
            auto b = res.begin(), e = res.end(); e--;

            if (val == "1")         res.erase(e);
            else if (val == "-1")   res.erase(b);
            
            break;
        }

        stoi(val);
    }

    auto b = res.begin(), e = res.end();
    if (b == e) {
        return { 0, 0 };
    } else {
        e--;
        return { *e, *b };
    }
}

void solution_3_3() {
    AutomatedInput Input;
    Input.set(
        "1 "

        "2 "
        "I 16 "
        "D 1 "

        "4 "
        "I 7 "
        "I 5 "
        "I -5 "
        "D -1"
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        size_t n;
        Input >> n;

        vector<string> operations(n);
        
        for (size_t i = 0; i < n; i++) {
            string tmp1, tmp2;
            Input >> tmp1 >> tmp2;
            operations[i] = tmp1 + " " + tmp2;
        }

        vector<int> result = solution(operations);
        cout << result[0] << " " << result[1] << endl;
    }
}