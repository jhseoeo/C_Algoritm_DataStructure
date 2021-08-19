#include "Problems7.h"

#include <string>
#include <vector>

using namespace std;

int findNum(const int& N, const int& number,
            int depth, int curNum) {

    if (depth > 8)              return 999;
    else if (curNum < 0)        return 999;
    else if (curNum > 100000)   return 999;
    else if (curNum == number)  return depth;

    int ret = 999;

    int D = N;
    for (int i = 1; i <= 5; i++) {
        ret = min(ret, findNum(N, number, depth + i, curNum + D));
        ret = min(ret, findNum(N, number, depth + i, curNum - D));
        ret = min(ret, findNum(N, number, depth + i, curNum * D));
        ret = min(ret, findNum(N, number, depth + i, curNum / D));
        D = D * 10 + D;
    }

    return ret;
}

int solution(int N, int number) {
    int answer = findNum(N, number, 0, 0);
    return answer != 999 ? answer : -1;
}

void solution_7_1() {
    AutomatedInput Input;
    Input.set(
        "2 "
        "8 53 "
        "2 11 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int N, number;
        Input >> N >> number;

        cout << solution(N, number) << endl;
    }
}