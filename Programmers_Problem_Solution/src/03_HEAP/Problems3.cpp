#include "Problems3.h"

void Problem_3() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 3-1" << endl;
    cout << "2. 3-2" << endl;
    cout << "3. 3-3" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_3_1();
        break;
    case 2:
        solution_3_2();
        break;
    case 3:
        solution_3_3();
        break;
    default:
        break;
    }
}