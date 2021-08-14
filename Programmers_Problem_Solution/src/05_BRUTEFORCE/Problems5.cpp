#include "Problems5.h"

void Problem_5() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 5-1" << endl;
    cout << "2. 5-2" << endl;
    cout << "3. 5-3" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_5_1();
        break;
    case 2:
        solution_5_2();
        break;
    case 3:
        solution_5_3();
        break;
    default:
        break;
    }
}