#include "./001.h"

void p001() {
    int T, D, S;

    cin >> T;

    double* results = new double[T]; 

    cin >> D >> S;

    int* Dates = new int[D];

    for(int tries = 0; tries < T; tries++) {
        for(int i = 0; i < D; i++) {
            cin >> Dates[i];
        }
        
        double min = 100;

        for(int i = 0; i < D - (S - 1); i++) {
            double result = 0;
            for(int j = 0; j < S; j++) {
                result += Dates[i + j];
            }
            result = result / S;

            if(result < min) {
                min = result;
            }
        }

        results[tries] = min;
    }

    for(int i = 0; i < T; i++) {
        cout << results[i] << endl;;
    }

    return;
}