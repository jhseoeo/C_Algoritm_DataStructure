#include "Problems1.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

static int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> clothMap;
    for (size_t i = 0; i < clothes.size(); i++) {
        if (clothMap.find(clothes[i][1]) == clothMap.end())
            clothMap.insert({ clothes[i][1] , 1 });
        else
            clothMap[clothes[i][1]]++;
    }

    for (auto const& iter : clothMap) {
        answer *= (iter.second + 1);
    }

    return answer - 1;
}

void solution_1_3() {
    AutomatedInput Input;
    Input.set(
        "2 "
        
        "3 "
        "yellowhat headgear "
        "bluesunglasses eyewear "
        "green_turban headgear "
        
        "3 "
        "crowmask face "
        "bluesunglasses face "
        "smoky_makeup face "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        vector<vector<string>> clothes;
        int n;
        string cloth, type;

        Input >> n;
        for (int i = 0; i < n; i++) {
            Input >> cloth >> type;

            clothes.push_back( {cloth, type} );
        }

        cout << solution(clothes) << endl;
    }
}