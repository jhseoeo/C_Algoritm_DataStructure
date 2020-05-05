#include "./001.h"

// First trial of problem 1 
void p001() {
    int T;  // Number of trial
    int D;  // Number of days at each trial
    int S;  // cost of each date

    cin >> T;

    // result of each trial
    double* results = new double[T]; 

    for(int tries = 0; tries < T; tries++) {

        cin >> D >> S;

        int* Dates = new int[D];

        for(int i = 0; i < D; i++) {
            cin >> Dates[i];
        }
        
        double min = 100;

        for(; S <= D; S++) {
            for(int i = 0; i + (S - 1) < D; i++) {
                double result = 0;
                for(int j = 0; j < S; j++) {
                    result += Dates[i + j];
                }
                result = result / S;

                if(result < min) {
                    min = result;
                }
            }
        }

        results[tries] = min;
    }

    for(int i = 0; i < T; i++) {
        cout << results[i] << endl;;
    }

    return;
}