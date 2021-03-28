/*
    Problem 001
    ID : FESTIVAL
*/

#include <iostream>
#include "../Problems.h"

using namespace std;

// First trial of problem 1 
void p001() {
    int T;  // Number of trial
    int D;  // Number of days at each trial
    int S;  // cost of each date

    cin >> T;

    // result of each trial
    double* results = new double[T]; 

    for(int tries = 0; tries < T; tries++) {

        cin >> D >> S; // number of all days, and number of days that we count continously

        int* Dates = new int[D];

        for(int i = 0; i < D; i++) { // getting costs of dates
            cin >> Dates[i];
        }
        
        double min = 100; // minimum cost. it initialized with maximum possible value.

        for(; S <= D; S++) { // looping by increase the number of continous days.
            for(int i = 0; i + (S - 1) < D; i++) { // set each starting point of continous days.
                double result = 0;
                for(int j = 0; j < S; j++) {
                    result += Dates[i + j] * 1.0; 
                }
                result = result / S; // getting average cost.

                if(result < min) {
                    min = result;   // if average cost per day is smaller than minimum cost before, switch it.
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