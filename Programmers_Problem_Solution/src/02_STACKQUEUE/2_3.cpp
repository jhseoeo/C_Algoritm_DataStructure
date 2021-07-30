#include "Problems2.h"

#include <string>
#include <vector>

using namespace std;

static int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    
    size_t numTrucks = truck_weights.size();
    vector<int> position(numTrucks), truckOnBridge;
    int currentWeight = 0;

    for (size_t i = 0; i < numTrucks;) {
        if (currentWeight + truck_weights[i] <= weight) {
            for (const int num : truckOnBridge)
                if (position[num] > bridge_length) break;
                else position[num]++;

            if (!truckOnBridge.empty() && position[truckOnBridge[0]] > bridge_length) {
                currentWeight -= truck_weights[truckOnBridge[0]];
                truckOnBridge.erase(truckOnBridge.begin());
            }

            currentWeight += truck_weights[i];
            truckOnBridge.push_back(i);
            position[i]++;
            time++;
            i++;
        } else {
            int distance = bridge_length - position[truckOnBridge[0]] + 1 ;

            for (const int num : truckOnBridge)
                position[num] += distance;

            currentWeight -= truck_weights[truckOnBridge[0]];
            truckOnBridge.erase(truckOnBridge.begin());

            if (currentWeight + truck_weights[i] <= weight) {
                currentWeight += truck_weights[i];
                truckOnBridge.push_back(i);
                position[i]++;
                i++;
            }
            time += distance;
        }

        cout << time << " <";
        for (int i = 0; i < truckOnBridge.size(); i++) {
            cout << truckOnBridge[i] << " ";
        }
        cout << "> " << endl;
    }

    int i = position.size() - 1;
    int distance = bridge_length - position[i] + 1;
    time += distance;

    return time;
}

void solution_2_3() {
    AutomatedInput Input;
    Input.set(
        "3 "

        "2 10 4 "
        "7 4 5 6 "

        "100 100 1 "
        "10 "

        "100 100 10 "
        "10 10 10 10 10 10 10 10 10 10 "
    );

    int T;
    Input >> T;

    for (int trial = 0; trial < T; trial++) {
        int bridge_length, weight, n;
        Input >> bridge_length >> weight >> n;
        vector<int> truck_weight(n);
        for (int i = 0; i < n; i++)
            Input >> truck_weight[i];

        cout << solution(bridge_length, weight, truck_weight) << endl;
    }
} 