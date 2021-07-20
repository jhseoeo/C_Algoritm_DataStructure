#include "Problems.h"

void Problem_1() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 1-1" << endl;
    cout << "2. 1-2" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_1_1();
        break;
    case 2:
        solution_1_2();
        break;
    default:
        break;
    }
}